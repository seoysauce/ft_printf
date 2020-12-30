/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_diux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 16:27:24 by seojeong          #+#    #+#             */
/*   Updated: 2020/12/30 16:27:28 by seojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_diux_1(t_info *info, int *size, long long data, const char *form) //출력 전 공백, 0의 개수를 set하는 함수.
{
	if (info->flag == 2)//flag가 0일 때,
	//'0'플래그가 살아있는 경우는
	//정밀도가 존재하지않을 때, printf("[%05d]",123) [00123]
	//정밀도가 음수일때  printf("[%05.*d]",-2,123) [00123]
	//정밀도가 data보다 클때 printf("[%05.4d",123) [ 0123]
	//폭이 가장 큰경우 2가지 고려.
	{
		if (info->prec <= leng(data, form) && leng(data, form) <= info->width)
		//정밀도 <= data의 길이 <= 폭인경우. 폭과 data길이차만큼 0추가해주면됨.
		//폭이 가장 큰경우 case1
		//"[%04d]",100 =>[0100], "[%04.*d]",-6,100 =>[0100]
			size[1] = info->width - leng(data, form);//'0'추가할 갯수
		else if (leng(data, form) <= info->prec && info->prec <= info->width)
		//data길이<=정밀도<=폭인경우.
		//폭이 가장 큰경우 case2   flag가 0이여도 폭-정밀도 만큼 공백이 추가됨.
		//[%06.5d]\n",100 => [ 00100]
		{
			size[0] = info->width - info->prec;//공백갯수
			size[1] = info->prec - leng(data, form);//'0'갯수
		}
		else if (info->width <= info->prec && leng(data, form) <= info->prec)
		//폭 <= data길이 <= 정밀도
		//정밀도가 가장 큰 경우에는 폭 무시.
		//[%02.5d]\n",100 => [00100]
			size[1] = info->prec - leng(data, form);//'0'의 갯수
		if (data < 0 && info->prec < leng(data, form))
		//data가 음수일 경우 && 정밀도 < data길이인 경우.
		//폭을 고려안하는 이유는 폭이 data보다 크나 작으나 data 그대로 출력됨.
		//정밀도가 길이보다 크다면 '-'부호는 '0'개수에 영향을 주지않고 사용된다.
		//printf("[%05.*d]",-2,-123); [-0123]
		//printf("[%06.*d]",-2,-123); [-00123]
		//printf("[%02.*d]",-2,-123); [-123]
			size[1]--;//'-'부호를 넣기위해서 0개수 하나빼준다.
	}
	else//- or flag 없는 경우.
	{
		size[1] = info->prec - leng(data, form);
		if (size[1] < 0)//정밀도가 작다면 정밀도는 필요없다.
			size[1] = 0;//'0'은 없다
			//printf("[%05.2d]\n",-100);  => [ -100]
		size[0] = info->width - size[1] - leng(data, form); // 공백의 갯수구하기
		if (data == 0 && info->point_zero)
			size[0]++;//data값이 0이고 정밀도가 0이면 0은 출력X => 공백추가
			//printf("[%05.d]",0)  => [     ]
			//printf("[%05d]",0)  => [00000]
	}
	if (data < 0)
		size[0]--;//'-'부호추가 공백개수 줄여줌.
}

void	print_diux_2(t_info *info, int *size, long long data, const char *form)
{
	//출력하는 부분.
	int i;

	i = -1;
	while (info->flag != 1 && ++i < size[0])
		write(1, &" ", 1);
	if (data < 0 && ++(info->ret))
		write(1, &"-", 1);
	i = -1;
	while (++i < size[1])
	{
		write(1, &"0", 1);
		(info->ret)++;
	}
	if (!(info->point_zero == 1 && data == 0))
	{
		ft_put_data(data, form);
		info->ret += leng(data, form);
	}
	i = -1;
	while (info->flag == 1 && ++i < size[0])
		write(1, &" ", 1);
	i = -1;
	while (++i < size[0])
		(info->ret)++;
}

void	print_diux(t_info *info, va_list ap, const char *form)
{
	long long	data;
	//unsigned int 와 int를 받기위해서 longlong선언
	int			size[2];

	data = 0;
	if (*form == 'u' || *form == 'x' || *form == 'X')
		data = va_arg(ap, unsigned int);
	else if (*form == 'd' || *form == 'i')
		data = va_arg(ap, int);
	arr_init(size, 2); //배열 0으로 초기화.
	//[0]공백
	//[1]0개수
	if (info->prec <= leng(data, form))//정밀도 보다 data길이가 큰경우.
	{
		if (info->prec > 0 && info->flag == 2)//정밀도가 0보다 크고 flag'0'이 존재한다면
			//ft_printf("[%05.3d]\n",1234);  [ 1234]
			info->flag = 0; //즉, flag 0 을 없애준다.
	}
	print_diux_1(info, size, data, form);
	print_diux_2(info, size, data, form);
}
