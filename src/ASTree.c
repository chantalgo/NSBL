#include "ASTree.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include "ASTree.h"

/** create a leaf in AST */
struct Node* ast_new_leaf(int token, void * ptr) {
    struct Node* node = (struct Node *) malloc ( sizeof (struct Node) );
    node->nch = 0;
    node->child = NULL;
    node->symbol = NULL;            // default null
    switch (token) {
        case INTEGER_CONSTANT :
            node->token = INTEGER_CONSTANT;
            node->type  = INT_T;
            node->lexval.ival = atoi( (const char *) ptr );
            break;
        case FLOAT_CONSTANT :
            node->token = FLOAT_CONSTANT;
            node->type = FLOAT_T;
            node->lexval.fval = atof( (const char *) ptr );
            break;
        case TRUE :
            node->token = TRUE;
            node->type = BOOL_T;
            node->lexval.bval = true;
            break;
        case FALSE :
            node->token = FALSE;
            node->type = BOOL_T;
            node->lexval.bval = false;
            break;
        case STRING_LITERAL :
            node->token = STRING_LITERAL;
            node->type = STRING_T;
            node->lexval.sval = (char *) ptr;
            break;
        case IDENTIFIER :
            node->token = IDENTIFIER;
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
#ifdef _AST_DEBUG
    fprintf(stdout, "ast_new_leaf :: create ");
    ast_output_node(node,stdout,"\n");
#endif
    return node;
}

struct Node** ast_all_children(int n, ...){
    if (n<=0) return NULL;
    int i;
    va_list args;
    va_start (args, n);
    struct Node** child = (struct Node**) malloc ( sizeof(struct Node *) * n );
    for(i=0; i<n; ++i) { child[i] = va_arg(args, struct Node *); }
    va_end(args);
    return child;
}

struct Node* ast_new_node(int token, int nch, struct Node** child){
    struct Node* node = (struct Node *) malloc ( sizeof (struct Node) );
    node->token = token;
    node->type = UNKNOWN_T;
    node->nch = nch;
    node->child = child;
    node->symbol = NULL;
#ifdef _AST_DEBUG_NODE
    fprintf(stdout, "ast_new_node :: create \n");
    fprintf(stdout, "==DEBUG INFO==\n");
    ast_output_subtree(node, stdout,0);
#endif

    return node;
}

void ast_free(struct Node* node) {
    if ( node->token == STRING_LITERAL || node->token == IDENTIFIER ) 
        free(node->lexval.sval);        // malloc by LexAly.l
    return;
}

void ast_output_node(struct Node* node, FILE* out, const char * sep) {
    switch (node->token) {
        case INTEGER_CONSTANT :
            fprintf(out, "Node<INT>    : lexval = %d%s", node->lexval.ival, sep);break;
        case FLOAT_CONSTANT :
            fprintf(out, "Node<FLOAT>  : lexval = %f%s", node->lexval.fval, sep);break;
        case TRUE :
            fprintf(out, "Node<TRUE> %s", sep); break;
        case FALSE :
            fprintf(out, "Node<FALSE> %s", sep); break;
        case STRING_LITERAL :
            fprintf(out, "Node<STRING> : lexval = %s%s", node->lexval.sval, sep);break;
        case IDENTIFIER :
            fprintf(out, "Node<ID>     : lexval = %s%s", node->lexval.sval, sep);break;
        case AST_TYPE_SPECIFIER :
            fprintf(out, "Node<TYPE>   : lexval = %s%s", s_table_type_name(node->lexval.ival), sep);break;
        case AST_DECLARATION :
            fprintf(out, "Node<DECLAR>%s", sep);break;
        case AST_FUNC_DECLARATOR :
            fprintf(out, "Node<FUNC_DECLARATOR>%s", sep);break;
        case BELONG :
            fprintf(out, "Node<BELONG>%s", sep);break;
        case AST_PARA_DECLARATION :
            fprintf(out, "Node<PARA_DECLARATION>%s", sep);break;
        case AST_LIST_INIT :
            fprintf(out, "Node<LIST_INIT>%s", sep);break;
        case AST_COMMA :
            fprintf(out, "Node<COMMA>%s", sep);break;
        case AST_ASSIGN :
            fprintf(out, "Node<ASSIGN>%s", sep);break;
        case ADD_ASSIGN :
            fprintf(out, "Node<ADD_ASSIGN>%s", sep);break;
        case SUB_ASSIGN :
            fprintf(out, "Node<SUB_ASSIGN>%s", sep);break;
        case MUL_ASSIGN :
            fprintf(out, "Node<MUL_ASSIGN>%s", sep);break;
        case DIV_ASSIGN :
            fprintf(out, "Node<DIV_ASSIGN>%s", sep);break;
        case OR :
            fprintf(out, "Node<OR>%s", sep);break;
        case AND :
            fprintf(out, "Node<AND>%s", sep);break;
        case EQ :
            fprintf(out, "Node<EQ>%s", sep);break;
        case NE :
            fprintf(out, "Node<Ne>%s", sep);break;
        case LT :
            fprintf(out, "Node<LT>%s", sep);break;
        case GT :
            fprintf(out, "Node<GT>%s", sep);break;
        case LE :
            fprintf(out, "Node<LE>%s", sep);break;
        case GE :
            fprintf(out, "Node<GE>%s", sep);break;
        case ADD :
            fprintf(out, "Node<ADD>%s", sep);break;
        case SUB :
            fprintf(out, "Node<SUB>%s", sep);break;
        case MUL :
            fprintf(out, "Node<MUL>%s", sep);break;
        case DIV :
            fprintf(out, "Node<DIV>%s", sep);break;
        case AST_CAST :
            fprintf(out, "Node<CAST>%s", sep);break;
        case AST_UNARY_PLUS :
            fprintf(out, "Node<UNARY_PLUS>%s", sep);break;
        case AST_UNARY_MINUS :
            fprintf(out, "Node<UNARY_MINUS>%s", sep);break;
        case AST_UNARY_NOT :
            fprintf(out, "Node<UNARY_NOT>%s", sep);break;
        case ARROW :
            fprintf(out, "Node<ARROW>%s", sep);break;
        case PIPE :
            fprintf(out, "Node<PIPE>%s", sep);break;
        case AST_MATCH :
            fprintf(out, "Node<MATCH>%s", sep);break;
        case AST_ATTIBUTE :
            fprintf(out, "Node<ATTRIBUTE>%s", sep);break;
        case AST_GRAPH_PROP :
            fprintf(out, "Node<GRAPH_PROP>%s", sep);break;
        case AST_STAT_LIST :
            fprintf(out, "Node<STAT_LIST>%s", sep);break;
        case AST_COMP_STAT :
            fprintf(out, "Node<COMP_STAT>%s", sep);break;
        default :
            fprintf(out, "Node<UNKNOWN> !!!!!!!!!!!!!!!!\n");
    }
    return;
}
    
void ast_output_subtree(struct Node* node, FILE* out, int level) {
    int i;
    fprintf(out, "TreeLevel<%4d>:: ",level);
    ast_output_node(node, out, "\n");
    for(i=0; i<node->nch; ++i) {
        ast_output_subtree(node->child[i],out,level+1);
    }
}
