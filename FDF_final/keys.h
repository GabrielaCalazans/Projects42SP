/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 10:31:24 by jaleman           #+#    #+#             */
/*   Updated: 2023/03/22 16:55:14 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

//  * * Source: "X11/keysymdef.h"
//  * TTY function keys, cleverly chosen to map to ASCII, for convenience of
//  * programming, but could have been arbitrary (at the cost of lookup
//  * tables in client code).
//  * Latin 1
//  * (ISO/IEC 8859-1 = Unicode U+0020..U+00FF)
//  * Byte 3 = 0

# define KEY_ESCAPE		0xff1b
# define KEY_LEFTARROW	0xff51  /* Move left, left arrow */
# define KEY_UPARROW	0xff52  /* Move up, up arrow */
# define KEY_RIGHTARROW	0xff53  /* Move right, right arrow */
# define KEY_DOWNARROW	0xff54  /* Move down, down arrow */
# define KEY_SPACE		0x0020  /* U+0020 SPACE */
# define KEY_A			0x0061  /* U+0061 LATIN SMALL LETTER A */
# define KEY_B			0x0062  /* U+0062 LATIN SMALL LETTER B */
# define KEY_C			0x0063  /* U+0063 LATIN SMALL LETTER C */
# define KEY_D			0x0064  /* U+0064 LATIN SMALL LETTER D */
# define KEY_E			0x0065  /* U+0065 LATIN SMALL LETTER E */
# define KEY_F			0x0066  /* U+0066 LATIN SMALL LETTER F */
# define KEY_G			0x0067  /* U+0067 LATIN SMALL LETTER G */
# define KEY_H			0x0068  /* U+0068 LATIN SMALL LETTER H */
# define KEY_I			0x0069  /* U+0069 LATIN SMALL LETTER I */
# define KEY_J			0x006a  /* U+006A LATIN SMALL LETTER J */
# define KEY_K			0x006b  /* U+006B LATIN SMALL LETTER K */
# define KEY_L			0x006c  /* U+006C LATIN SMALL LETTER L */
# define KEY_M			0x006d  /* U+006D LATIN SMALL LETTER M */
# define KEY_N			0x006e  /* U+006E LATIN SMALL LETTER N */
# define KEY_O			0x006f  /* U+006F LATIN SMALL LETTER O */
# define KEY_P			0x0070  /* U+0070 LATIN SMALL LETTER P */
# define KEY_Q			0x0071  /* U+0071 LATIN SMALL LETTER Q */
# define KEY_R			0x0072  /* U+0072 LATIN SMALL LETTER R */
# define KEY_S			0x0073  /* U+0073 LATIN SMALL LETTER S */
# define KEY_T			0x0074  /* U+0074 LATIN SMALL LETTER T */
# define KEY_U			0x0075  /* U+0075 LATIN SMALL LETTER U */
# define KEY_V			0x0076  /* U+0076 LATIN SMALL LETTER V */
# define KEY_W			0x0077  /* U+0077 LATIN SMALL LETTER W */
# define KEY_X			0x0078  /* U+0078 LATIN SMALL LETTER X */
# define KEY_Y			0x0079  /* U+0079 LATIN SMALL LETTER Y */
# define KEY_Z			0x007a  /* U+007A LATIN SMALL LETTER Z */

#endif
