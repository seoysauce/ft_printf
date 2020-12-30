/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 16:27:03 by seojeong          #+#    #+#             */
/*   Updated: 2020/12/30 16:27:07 by seojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void print_c(t_info *info, va_list ap, const char *form)
//정밀도를 신경써줄필요가없다. printf("%.c",'a'); printf("%.0c") printf("%.-1c")    === a
{
	int i;
	char data;

	if (*form == 'c')
		data = va_arg(ap, int); //data에 출력할 문자 저장 a저장됨.
	else						//char, short 의 경우에는 int로 씀.
		data = '%'; //printf("%%");
	i = -1;
	if (info->flag == 2) // flag = 0인 경우임. 앞에 0으로 채움.
		while (++i < info->width - 1)
			write(1, &"0", 1);
	if (info->flag == 0) //'0','-'플래그 존재X
		while (++i < info->width - 1)
			write(1, &" ", 1);
	write(1, &data, 1);
	(info->ret)++; //문자 1개니까 ++
	i = -1;
	if (info->flag == 1)			  //'-'플래그 존재할 경우
		while (++i < info->width - 1) //문자 출력하고 폭의 수 -1 만큼 뒤에 공백출력
			write(1, &" ", 1);
	i = -1;
	while (++i < info->width - 1) //출력된 공백 또는 0개수만큼 결과값에 더해주기
		(info->ret)++;
}

void print_p(t_info *info, va_list ap)
//폭과 '-'플래그, point_zero에 영향을 받는다.
{
	unsigned long long data; //64bit
	int i;

	data = va_arg(ap, unsigned long long); //64bit 8byte
	i = -1; //
	if (info->flag != 1) //flag가 -가 아니면 앞 공백.
		while (++i < info->width - hex_leng_2(data, info->point_zero) - 2)
			write(1, &" ", 1); //2가 0,x자리  hex_leng_2가 p자리 세는 것.
	write(1, &"0x", 2);
	if (!(data == 0 && info->point_zero))
		//data값이 0이고 정밀도가 0인 경우를 제외하고 모든 경우 p 출력.
		//ft_printf("%.0p\n",0);  0x
		//ft_printf("%p\n",0);    0x0
		ft_putthex2(data);
	if (info->flag == 1) //flag가 - 인경우 뒤의 공백
		while (++i < info->width - hex_leng_2(data, info->point_zero) - 2)
			write(1, &" ", 1);
	info->ret += 2 + hex_leng_2(data, info->point_zero); //0x + 값
	i = -1;
	while (++i < info->width - hex_leng_2(data, info->point_zero) - 2) //공백 값.
		(info->ret)++;
}

void print_s_1(t_info *info, int *size, char *data) //출력담당.
//문자열은 '0'플래그무시
{
	//폭이 가장 작은경우에는 정밀도가 작은지 문자열이 작은지 경우의 수를 2가지 고려해야한다.
	if (info->width <= info->prec && info->prec <= ft_strlen(data))
		//폭 <= 정밀도 <= 문자열 인 경우. 정밀도에 영향을 받음.
		//"%1.2s","abc" => [ab]
		size[0] = info->prec;
	else if (info->width <= ft_strlen(data) && ft_strlen(data) <= info->prec)
		//폭 <= 문자열 <= 정밀도인 경우.  문자열그대로 출력.
		//"%1.4s","abc" =>[abc]
		size[0] = ft_strlen(data);
	else if (info->prec <= info->width && info->prec <= ft_strlen(data))
	//정밀도 <= 폭 <= 문자열인 경우  폭과 정밀도에 영향을 받음.
	//"%5s","abcd" => [ abcd]
	//"%5.2s","abcd" => [   ab]
	//"%.s", "abc" => []
	{
		size[0] = info->prec; //출력할 문자개수.
		size[1] = info->width - info->prec; //공백 개수
	}
	else if (ft_strlen(data) <= info->width && ft_strlen(data) <= info->prec)
	//문자열 <= 폭 <= 정밀도인 경우.  폭과 문자열만 영향.
	//"%4.3s","ab"=>[  ab]
	{
		size[0] = ft_strlen(data);
		size[1] = info->width - ft_strlen(data);
	}
	if (info->point_zero)
	//.0일경우 폭만 출력됨.
	//"%5.0s","abc"=>[     ]
	{
		size[0] = 0;
		size[1] = info->width;
	}
}

void print_s(t_info *info, va_list ap)
//'0'플래그는 무시.따로 고려 x . ft_printf("[%010s\n]","hello"); //[     hello]
//정밀도가 음수이면 문자열 전체출력, point zero 이면  ft_printf("[%10.s]\n","hello"); [          ]
//정밀도가 1 -> 1개,2 -> 2개
//만약 문자열이 "abc"이고 정밀도가 4 이상이면 무시된다. ft_printf("[%.4s]\n","abc"); //[abc]
{
	char *data;
	int size[2];
	int i;

	arr_init(size, 2); //int타입의 배열2개 생성
	//[0]-> 출력되는 문자의 개수
	//[1]-> 공백개수
	data = ft_strdup(va_arg(ap, char *));
	if (data == NULL)
		data = ft_strdup("(null)");
	if (info->prec <= 0)
		//printf("[%*s]",3,"hello");  -> [hello] return 5
		info->prec = ft_strlen(data); //정밀도가 문자열 길이보다 작으면 길이로 초기화해줌.
	print_s_1(info, size, data); //출력부분
	i = -1;
	if (info->flag != 1) //flag가 0일 경우
		while (++i < size[1])
			write(1, &" ", 1); //문자열은 0이아닌 공백으로 출력됨
	write(1, data, size[0]); //문자출력 size[0] 개수만큼.
	if (info->flag == 1) //flag가 -인 경우
		while (++i < size[1]) //문자열 뒤 공백출력.
			write(1, &" ", 1);
	info->ret += size[0];
	i = -1;
	while (++i < size[1])
		(info->ret)++;
	free(data);
	data = NULL;
	//data를 NULL초기화 시키않는다면 중요한 정보가 data에 들어갈 경우 임의의 메모리가 들어가기때문에 나중에는 찾을 수 없다.
}
