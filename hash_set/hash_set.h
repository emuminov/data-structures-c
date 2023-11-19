/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_set.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:57:54 by emuminov          #+#    #+#             */
/*   Updated: 2023/11/19 20:32:32 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_SET_H
#define HASH_SET_H

#include "../base.h"

typedef struct {
	int base_size;
	int size;
	int length;
	int **items;
} hs_set;

// TODO: move to hash folder
unsigned int hash(int n);

hs_set *hs_new();
void hs_insert(int value, hs_set *hs);
void hs_remove(int value, hs_set *hs);
void hs_delete(hs_set *hs);
bool hs_has(int value, hs_set *hs);
void hs_print(hs_set *hs);

#define FNV_PRIME 16777619 
#define FNV_OFFSET 2166136261 
// change to 53
#define HS_INITIAL_BASE_SIZE 23
#endif
