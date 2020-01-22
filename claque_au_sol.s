# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    claque_au_sol.s                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ythomas <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/28 18:28:52 by ythomas           #+#    #+#              #
#    Updated: 2019/11/28 18:57:47 by ythomas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.name "claque_au_sol"
.comment "je viens deposer un SLAM"

ld		32, r3
ld		4, r4
ld		190, r5
st		r1, 6
boucle_this:
live	%666
sti		r5, r5, r3
add		r3, r4, r5
ld		%0, r16
zjmp	%:boucle_this
