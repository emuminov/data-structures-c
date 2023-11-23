/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_set.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:57:54 by emuminov          #+#    #+#             */
/*   Updated: 2023/11/23 10:49:46 by emuminov         ###   ########.fr       */
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
unsigned long long hash(int n);

hs_set *hs_new();
void hs_insert(int value, hs_set *hs);
void hs_remove(int value, hs_set *hs);
void hs_delete(hs_set *hs);
bool hs_has(int value, hs_set *hs);
void hs_print(hs_set *hs);

#define FNV_PRIME (unsigned long long) 1099511628211U
#define FNV_OFFSET (unsigned long long) 14695981039346656037U
// change to 53
#define HS_INITIAL_BASE_SIZE 23
#endif
