#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>


int	ft_printf(const char *format, ...)
{
	int	int_data;
	char	*p_string;
	va_list	ap;

	// 첫번째 가변 인수의 위치를 format을 가지고 결정한다.
	va_start(ap, format);

	while (*format) // format 문자열이 끝날 때까지(NULL 문자가 나올 때까지) 반복한다
	{
		if (*format == '%') // % 문자를 찾는다
		{
			format++;	// % 다음에 있는 문자로 이동한다
			if (*format == 'c') //문자도 ASCII 코드 값으로 처리하기 때문에 int형식으로 값을 읽는다
			{
				int_data = va_arg(ap, int);
				write(1, &int_data, 1); //int_data int 크기(4바이트) 만큼 출력
			}
			else if (*format == 'd')
			{
				int_data = va_arg(ap, int);
				write(1, &int_data, 1);
			}
			else if (*format == 's')
			{
				p_string = va_arg(ap, char *);
				if (p_string != NULL)
					write(1, p_string, 6);
			}
			else{
				printf("Invalid Format!");
				return (-1);
			}
		}
		else // 일반 문자는 그대로 출력한다
		{
			write(1, format, 1);
		}
		format++; //다음 문자로 이동한다
	}
	va_end(ap); // 다 끝난 후 ap를 NULL로 초기화해준다.
	return (0);
}

int	main(void)
{
	ft_printf("Hello %c class!, I'm %d years old and my name is %s", 'A', '2', "Jidong");
}
