#ifndef YORHA_LIST_H
#define YORHA_LIST_H

#include <stdbool.h>

#define LIST_DECLARE(NAME) struct NAME##_list;
#define LIST_DEFINE(NAME, TYPE)                                               \
struct NAME##_list {                                                          \
	struct NAME##_list *next;                                             \
	struct NAME##_list *prev;                                             \
	TYPE node;                                                            \
};                                                                            \
                                                                              \
static inline NAME##_list *                                                   \
NAME##_listinit(struct NAME##_list *lp)                                       \
{                                                                             \
	lp->next = lp;                                                        \
	lp->prev = lp;                                                        \
	return lp;                                                            \
}                                                                             \
                                                                              \
static inline void                                                            \
NAME##_listadd(struct NAME##_list *head, struct NAME##_list *new)             \
{                                                                             \
	new->next = head;                                                     \
	new->prev = head->prev;                                               \
	new->prev->next = new;                                                \
	new->next->prev = new;                                                \
}                                                                             \
                                                                              \
static inline NAME##_list *                                                   \
NAME##_listrm(struct NAME##_list *lp)                                         \
{                                                                             \
	lp->prev->next = lp->next;                                            \
	lp->next->prev = lp->prev;                                            \
	return lp;                                                            \
}                                                                             \
                                                                              \
static inline void                                                            \
NAME##_listxch(struct NAME##_list *old, struct NAME##_list *new)              \
{                                                                             \
	old->next->prev = new;                                                \
	old->prev->next = new;                                                \
	new->next = old->next;                                                \
	new->prev = old->prev;                                                \
}                                                                             \
                                                                              \
static inline bool                                                            \
NAME##_listempty(struct NAME##_list *lp)                                      \
{                                                                             \
    return !(lp == lp->next) || !(lp == lp->prev);                            \
}

#endif
