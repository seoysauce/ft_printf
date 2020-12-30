/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 17:01:23 by seojeong          #+#    #+#             */
/*   Updated: 2020/12/30 16:26:04 by seojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"

int main(void)
{
printf("[%0.3s]","hello");
printf("%.c",'a');
printf("%.1c",'a');
printf("%.-1c\n",'a');
write(1,&" ",1);
printf("----------\n");
printf("[%010p]\n",0);//?????
ft_printf("[%010p]\n",0); //[        0x]
ft_printf("[%10.p]\n",0); //[        0x]
ft_printf("[%10p]\n",0);  //[       0x0]
ft_printf("%.0p\n",0); //0x
ft_printf("%p\n",0); //0x0
ft_printf("[%.4s]\n","abc"); //[abc]
ft_printf("%p\n",0); //0x0
ft_printf("[%05.3d]\n",1234);  //[ 1234]
 printf("[%05.*d]\n",-2,123);
 printf("[%06.5d]\n",100);
printf("[%05.*d]",-2,-123);
printf("[%06.*d]",-2,-123);
printf("[%02.*d]",-2,-123);
}
