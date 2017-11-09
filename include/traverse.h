m_bool traverse_ast(Env env, Ast ast);
m_bool traverse_class_def(Env env, Class_Def def);
m_bool traverse_func_def(Env env, Func_Def def);
m_bool traverse_stmt_union(Env env, Stmt_Union stmt);
m_bool traverse_stmt_enum(Env env, Stmt_Enum stmt);
m_bool traverse_stmt_fptr(Env env, Stmt_Ptr stmt);
m_bool traverse_decl(Env env, Exp_Decl* decl);

Class_Def template_class(Env env, Class_Def def, Type_List call);
m_bool template_push_types(Env env, ID_List base, Type_List call);
