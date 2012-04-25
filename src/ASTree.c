#include "ASTree.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include "util.h"
#include "CodeGen.h"
#include "global.h"

#ifdef _AST_DEBUG_BASE
extern FILE* DEBUGIO;
#endif

/** create a leaf in AST */
struct Node* ast_new_leaf(int token, void * ptr, long long line) {
    struct Node* node = (struct Node *) malloc ( sizeof (struct Node) );   // free in ast_free_tree
    node->typeCon = NULL;
    node->nch = 0;                  // Leaf has no child
    node->child = NULL;             
    node->symbol = NULL;            // default null
    node->line = line;              // line # in source
    node->code = NULL;              // no code assigned
    node->codetmp = NULL;
    node->scope[0] = sStackLevel;
    node->scope[1] = sStackTopId;
    node->tmp[0] = 0;
    switch (token) {
        case INTEGER_CONSTANT :
            node->token = INTEGER_CONSTANT;
            node->type  = INT_T;
            node->lexval.ival = atoi( (const char *) ptr );
            node->code = strCatAlloc("", 1, (const char *)ptr);
            break;
        case FLOAT_CONSTANT :
            node->token = FLOAT_CONSTANT;
            node->type = FLOAT_T;
            node->lexval.fval = atof( (const char *) ptr );
            node->code = strCatAlloc("", 1, (const char *)ptr);
            break;
        case BOOL_TRUE :
            node->token = BOOL_TRUE;
            node->type = BOOL_T;
            node->lexval.bval = true;
            node->code = strCatAlloc("", 1, "true");
            break;
        case BOOL_FALSE :
            node->token = BOOL_FALSE;
            node->type = BOOL_T;
            node->lexval.bval = false;
            node->code = strCatAlloc("", 1, "false");
            break;
        case STRING_LITERAL :
            node->token = STRING_LITERAL;
            node->type = STRING_T;
            node->lexval.sval = (char *) ptr;
            node->code = strCatAlloc("", 1, (const char *)ptr);
            break;
        case IDENTIFIER :
            node->token = IDENTIFIER;
            node->type = UNKNOWN_T;
            node->lexval.sval = (char *) ptr;
            break;
        case DYN_ATTRIBUTE :
            node->token = DYN_ATTRIBUTE;
            node->type = UNKNOWN_T;
            node->lexval.sval = (char *) ptr;
            break;
        case AST_TYPE_SPECIFIER :
            node->token = AST_TYPE_SPECIFIER;
            node->type = UNKNOWN_T;
            node->lexval.ival = *((int *) ptr);
            break;
        case ALL_VERTICES :
            node->token = ALL_VERTICES;break;
        case ALL_EDGES :
            node->token = ALL_EDGES;break;
        case OUTCOMING_EDGES :
            node->token = OUTCOMING_EDGES;break;
        case INCOMING_EDGES :
            node->token = INCOMING_EDGES;break;
        case STARTING_VERTICES :
            node->token = STARTING_VERTICES;break;
        case ENDING_VERTICES :
            node->token = ENDING_VERTICES;break;
        default:
            fprintf(stderr,"ast_new_leaf: unknown token: %d\n",token);
    }
#ifdef _AST_DEBUG_BASE
    debugInfo("ast_new_leaf :: create ");
    ast_output_node(node,DEBUGIO,"\n");
#endif
    return node;
}

struct Node** ast_all_children(int n, ...){
    if (n<=0) return NULL;
    int i;
    va_list args;
    va_start (args, n);
    struct Node** child = (struct Node**) malloc ( sizeof(struct Node *) * n );  // free in ast_free_tree
    for(i=0; i<n; ++i) { child[i] = va_arg(args, struct Node *); }
    va_end(args);
    return child;
}

struct Node* ast_new_node(int token, int nch, struct Node** child, long long line){
    struct Node* node = (struct Node *) malloc ( sizeof (struct Node) );  // free in ast_free_tree
<<<<<<< HEAD
	if(token==BELONG && 0){   // not used 
		char* temp = strCatAlloc("", 3, child[1]->lexval.sval, "_", child[0]->lexval.sval);
		//child[1]->code = child[1]->lexval.sval;
		child[1]->lexval.sval = temp;
	}
=======
>>>>>>> [I/O] Grammar and CodeGen for IO complete
    node->token = token;
    node->type = UNKNOWN_T;             // default
    node->typeCon = NULL;
    node->nch = nch;                    // assign children
    node->child = child;        
    node->symbol = NULL;                // default NULL
    node->line = line;                  // line # in source (for corresponding token)
    node->code = NULL;                  
    node->codetmp = NULL;
    node->scope[0] = sStackLevel;
    node->scope[1] = sStackTopId;
    node->tmp[0] = 0;
#ifdef _AST_DEBUG_EXTRA
    debugInfo("ast_new_node :: create \n");
    debugInfo("==DEBUG INFO==\n");
    ast_output_tree(node, stdout,0);
#endif
    return node;
}

void ast_free_tree(struct Node* node) {
    if ( node == NULL ) return;
#ifdef _AST_DEBUG_MEMORY
    debugInfo("TO FREE node:");
    ast_output_node(node, DEBUGIO, "\n");
#endif
    /* free sval */
    if ( node->token == STRING_LITERAL || node->token == IDENTIFIER ) {
#ifdef _AST_DEBUG_MEMORY
        debugInfo("FREE sval: %s\n",node->lexval.sval); 
#endif
        free(node->lexval.sval);        // malloc by LexAly.l
    }
    /* free code */
    if ( node->code != NULL ) {
#ifdef _AST_DEBUG_MEMORY
        debugInfo("FREE code: %s\n", node->code);
#endif
        free(node->code);
    }
    if ( node->codetmp != NULL ) {
#ifdef _AST_DEBUG_MEMORY
        debugInfo("FREE codetmp: %s\n", node->codetmp);
#endif
        free(node->codetmp);
    }
    /* if child exsits, free child first */
    if ( node->nch > 0 && node->child != NULL ) {
        // free children
        int i;for(i=0; i<node->nch; ++i) ast_free_tree( node->child[i] );
        // free child ptr array
#ifdef _AST_DEBUG_MEMORY
        debugInfo("FREE child ptrs in ");
        ast_output_node(node, DEBUGIO, "\n");
#endif
        free(node->child);
    }
    else if (node->nch > 0 || node->child != NULL) {
        fprintf(stderr, "ERROR:: ast_free_tree :: nch does NOT match child! code bug detected!!\n ");
    }
    /* free myself */
#ifdef _AST_DEBUG_MEMORY
    debugInfo("FREE this node\n");
#endif
    free(node);
    return;
}

void ast_output_node(struct Node* node, FILE* out, const char * sep) {
    if(node==NULL) return;
    fprintf(out,"%lld::",node->line);
    switch (node->token) {
        case INTEGER_CONSTANT :
            fprintf(out, "Node<INT>    : lexval = %d", node->lexval.ival);break;
        case FLOAT_CONSTANT :
            fprintf(out, "Node<FLOAT>  : lexval = %f", node->lexval.fval);break;
        case BOOL_TRUE :
            fprintf(out, "Node<TRUE> "); break;
        case BOOL_FALSE :
            fprintf(out, "Node<FALSE> "); break;
        case STRING_LITERAL :
            fprintf(out, "Node<STRING> : lexval = %s", node->lexval.sval);break;
        case IDENTIFIER :
            fprintf(out, "Node<ID>     : lexval = %s  type = %d  ", node->lexval.sval, node->type);
            if(node->symbol!=NULL) fprintf(out, "bind = %s", node->symbol->bind);
            break;
        case DYN_ATTRIBUTE:
            fprintf(out, "node<DYN_ATTR>: lexval = %s  type = %d ", node->lexval.sval, node->type);
            if(node->symbol!=NULL) fprintf(out, "bind = %s", node->symbol->bind);
            break; 
        case AST_TYPE_SPECIFIER :
            fprintf(out, "Node<TYPE>   : lexval = %s", s_table_type_name(node->lexval.ival));break;
        case AST_DECLARATION :
            fprintf(out, "Node<DECLAR>");break;
        case AST_FUNC_DECLARATOR :
            fprintf(out, "Node<FUNC_DECLARATOR>");break;
        case BELONG :
            fprintf(out, "Node<BELONG>");break;
        case AST_PARA_DECLARATION :
            fprintf(out, "Node<PARA_DECLARATION>");break;
        case AST_LIST_INIT :
            fprintf(out, "Node<LIST_INIT>");break;
        case AST_COMMA :
            fprintf(out, "Node<COMMA>");break;
        case AST_ASSIGN :
            fprintf(out, "Node<ASSIGN>");break;
        case ADD_ASSIGN :
            fprintf(out, "Node<ADD_ASSIGN>");break;
        case SUB_ASSIGN :
            fprintf(out, "Node<SUB_ASSIGN>");break;
        case MUL_ASSIGN :
            fprintf(out, "Node<MUL_ASSIGN>");break;
        case DIV_ASSIGN :
            fprintf(out, "Node<DIV_ASSIGN>");break;
		case APPEND :
			fprintf(out, "Node<APPEND>");break;
        case OR :
            fprintf(out, "Node<OR>");break;
        case AND :
            fprintf(out, "Node<AND>");break;
        case EQ :
            fprintf(out, "Node<EQ>");break;
        case NE :
            fprintf(out, "Node<Ne>");break;
        case LT :
            fprintf(out, "Node<LT>");break;
        case GT :
            fprintf(out, "Node<GT>");break;
        case LE :
            fprintf(out, "Node<LE>");break;
        case GE :
            fprintf(out, "Node<GE>");break;
        case ADD :
            fprintf(out, "Node<ADD>");break;
        case SUB :
            fprintf(out, "Node<SUB>");break;
        case MUL :
            fprintf(out, "Node<MUL>");break;
        case DIV :
            fprintf(out, "Node<DIV>");break;
        case AST_CAST :
            fprintf(out, "Node<CAST>");break;
        case AST_UNARY_PLUS :
            fprintf(out, "Node<UNARY_PLUS>");break;
        case AST_UNARY_MINUS :
            fprintf(out, "Node<UNARY_MINUS>");break;
        case AST_UNARY_NOT :
            fprintf(out, "Node<UNARY_NOT>");break;
        case ARROW :
            fprintf(out, "Node<ARROW>");break;
        case PIPE :
            fprintf(out, "Node<PIPE>");break;
        case AST_MATCH :
            fprintf(out, "Node<MATCH>");break;
        case AST_ATTRIBUTE :
            fprintf(out, "Node<ATTRIBUTE>");break;
        case AST_GRAPH_PROP :
            fprintf(out, "Node<GRAPH_PROP>");break;
        case AST_STAT_LIST :
            fprintf(out, "Node<STAT_LIST>");break;
        case AST_COMP_STAT :
            fprintf(out, "Node<COMP_STAT>");break;
        case AST_COMP_STAT_NO_SCOPE :
            fprintf(out, "Node<COMP_STAT_NO_SCOPE>");break;
        case AST_EXT_STAT_COMMA :
            fprintf(out, "Node<EXT_STAT_COMMA>");break;
		case AST_FUNC :
			fprintf(out, "Node<FUNCTION>" );break;
		case FUNC_LITERAL:
			fprintf(out, "Node<FUNC_LITERAL>" );break;
		case AST_IF_STAT :
			fprintf(out, "Node<IF_STAT>");break;
		case AST_IFELSE_STAT :
			fprintf(out, "Node<IFELSE_STAT>");break;
		case AST_WHILE :
			fprintf(out, "Node<WHILE_STAT>");break;
		case AST_FOREACH :
			fprintf(out, "Node<FOREACH_STAT>");break;
		case AST_FOR :
			fprintf(out, "Node<FOR_STAT>");break;
		case AST_JUMP_CONTINUE:
			fprintf(out, "Node<CONTINUE>");break;
		case AST_JUMP_BREAK:
			fprintf(out, "Node<BREAK>");break;
		case AST_JUMP_RETURN:
			fprintf(out, "Node<RETRUN>");break;
		case AST_FUNC_CALL:
			fprintf(out, "Node<FUNC_CALL>  :");
            if(node->symbol!=NULL) fprintf(out, "bind = %s", node->symbol->bind);
            break;
		case ALL_VERTICES :
			fprintf(out, "Node<ALL_VERTICES>");break;
		case OUTCOMING_EDGES :
			fprintf(out, "Node<OUTEDGES>");break;
		case STARTING_VERTICES :
			fprintf(out, "Node<STARTING_VERTICES>");break;
		case ENDING_VERTICES :
			fprintf(out, "Node<ENDING_VERTICES>");break;
		case ALL_EDGES :
			fprintf(out, "Node<ALL_EDGES>");break;
		case INCOMING_EDGES:
			fprintf(out, "Node<INCOMING_EDGES>");break;
		case AT :
			fprintf(out, "Node<AT_ATTRIBUTE>");break;
        case AST_ARG_EXPS :
            fprintf(out, "Node<ARGUMENT_EXP>");break;
        case AST_EXP_STAT :
            fprintf(out, "Node<EXP_STAT>");break;
<<<<<<< HEAD
        case AST_ERROR :
            fprintf(out, "Node<ERROR>");break;
        case DEL :
            fprintf(out, "Node<DEL>");break;
=======
	case AST_PRINT :
	    fprintf(out, "Node<AST_PRINT>");break;
	case AST_PRINT_STAT :
 	    fprintf(out, "Node<AST_PRINT_STAT>");break;	
	case AST_READ_GRAPH :
	    fprintf(out, "Node<AST_READ_GRAPH>");break;
	case AST_WRITE_GRAPH :
	    fprintf(out, "Node<AST_WRITE_GRAPH>");break;
>>>>>>> [I/O] Grammar and CodeGen for IO complete
        default :
            fprintf(out, "Node<UNKNOWN> !!!!!!!!!!!!!!!!");
    }
    fprintf(out," lvl=%d ",node->scope[0]);
    if(node->code != NULL) fprintf(out," \n code =`%s`", node->code);
    if(node->codetmp != NULL) fprintf(out,"\n  codetmp =`%s`", node->codetmp);
    fprintf(out, "%s", sep);
    return;
}
    
/** preorder output */
void ast_output_tree(struct Node* node, FILE* out, int level) {
    int i;
	int indent = level;
    if(node == NULL) return;
	while(indent-->0){
		fprintf(out, "  ");
	}
    fprintf(out, "Tree<%d>::",level);
    ast_output_node(node, out, "\n");
    for(i=0; i<node->nch; ++i) {
        ast_output_tree(node->child[i],out,level+1);
    }
}

/** find the leftmost child */
struct Node* ast_leftmost_child(struct Node* node) {
    if( node == NULL ) return NULL;
    if( node->nch <= 0 ) return node;
    return ast_leftmost_child(node->child[0]);
}

/** create type construct for parameter_list */
GArray* ast_type_construct_parameter_list(struct Node* node, GArray* ga) {
    if(ga==NULL) ga = g_array_new (1,1,sizeof(int));                // destroy in SymbolTable.c
    if(node==NULL) return ga;
    if(node->token == AST_COMMA) {
        ast_type_construct_parameter_list(node->child[0],ga);      // left
        ast_type_construct_parameter_list(node->child[1],ga);      // right
    }
    else if(node->token == AST_PARA_DECLARATION ||
                node->token == FUNC_LITERAL ) {
        g_array_append_vals ( ga, (gconstpointer) & (node->type), 1 ); 
    }
    else {
        fprintf(stderr,"Error: ast_type_construct_parameter_list :: see unknown token : %d\n", node->token);
    }
    return ga;
}

/** create type construct for argument_expression_list */
GArray* ast_type_construct_argument_expression_list(struct Node* node, GArray* ga) {
    if(ga==NULL) ga = g_array_new (1,1,sizeof(int));                        // destory by ast_free_type_construct
    if(node==NULL) return ga;
    if(node->token == AST_COMMA) {
        ast_type_construct_argument_expression_list(node->child[0],ga);      // left
        ast_type_construct_argument_expression_list(node->child[1],ga);      // right
    }
    else if(node->token == AST_ARG_EXPS) {
        g_array_append_vals ( ga, (gconstpointer) & (node->type), 1 );
    }
    else {
        fprintf(stderr,"Error: ast_type_construct_argument_expression_list :: see unknown token : %d\n", node->token);
    }
    return ga;
}

void ast_free_type_construct(GArray* ga) {
    if(ga!=NULL) { 
        g_array_free(ga, 1);
        ga = NULL;
    }
}
