/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples_features.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 19:21:11 by gacalaza          #+#    #+#             */
/*   Updated: 2024/03/27 20:44:04 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minirt.h"

// Scenario: Concatenating two arrays should create a new array
// Given a ← array(1, 2, 3)
// And b ← array(3, 4, 5)
// When c ← a + b
// Then c = array(1, 2, 3, 3, 4, 5)


// Scenario: A tuple with w=1.0 is a point
// Given a ← tuple(4.3, -4.2, 3.1, 1.0)
// Then a.x = 4.3
// And a.y = -4.2
// And a.z = 3.1
// And a.w = 1.0
// And a is a point
// And a is not a vector

// Scenario: A tuple with w=0 is a vector
// Given a ← tuple(4.3, -4.2, 3.1, 0.0)
// Then a.x = 4.3
// And a.y = -4.2
// And a.z = 3.1
// And a.w = 0.0
// And a is not a point
// And a is a vector

// Scenario: point() creates tuples with w=1
// Given p ← point(4, -4, 3)
// Then p = tuple(4, -4, 3, 1)

// Scenario: vector() creates tuples with w=0
// Given v ← vector(4, -4, 3)
// Then v = tuple(4, -4, 3, 0)

// Scenario: Adding two tuples
// Given a1 ← tuple(3, -2, 5, 1)
// And a2 ← tuple(-2, 3, 1, 0)
// Then a1 + a2 = tuple(1, 1, 6, 1)

// constant EPSILON ← 0.00001
// function equal(a, b)
// if abs(a - b) < EPSILON
// return true
// else
// return false
// end if
// end function

// *********  Adding Tuples ********* 
// adding a point to a point doesn’t really make sense.

// Scenario: Adding two tuples
// Given a1 ← tuple(3, -2, 5, 1)
// And a2 ← tuple(-2, 3, 1, 0)
// Then a1 + a2 = tuple(1, 1, 6, 1)

// ********* Subtracting Tuples *********
//  subtract a point (w = 1) from a vector (w = 0),doesn’t really make sense.
// Scenario: Subtracting two points
// Given p1 ← point(3, 2, 1)
// And p2 ← point(5, 6, 7)
// Then p1 - p2 = vector(-2, -4, -6)

// Scenario: Subtracting a vector from a point
// Given p ← point(3, 2, 1)
// And v ← vector(5, 6, 7)
// Then p - v = point(-2, -4, -6)

// Scenario: Subtracting two vectors
// Given v1 ← vector(3, 2, 1)
// And v2 ← vector(5, 6, 7)
// Then v1 - v2 = vector(-2, -4, -6)

// ********* Negating Tuples *********
// Scenario: Subtracting a vector from the zero vector
// Given zero ← vector(0, 0, 0)
// And v ← vector(1, -2, 3)
// Then zero - v = vector(-1, 2, -3)

// Scenario: Negating a tuple
// Given a ← tuple(1, -2, 3, -4)
// Then -a = tuple(-1, 2, -3, 4)

// ********* Scalar Multiplication and Division *********
// Scenario: Multiplying a tuple by a scalar
// Given a ← tuple(1, -2, 3, -4)
// Then a * 3.5 = tuple(3.5, -7, 10.5, -14)

// Scenario: Multiplying a tuple by a fraction
// Given a ← tuple(1, -2, 3, -4)
// Then a * 0.5 = tuple(0.5, -1, 1.5, -2)

// Scenario: Dividing a tuple by a scalar
// Given a ← tuple(1, -2, 3, -4)
// Then a / 2 = tuple(0.5, -1, 1.5, -2)

// ********* Magnitude *********
// Scenario: Computing the magnitude of vector(1, 0, 0)
// Given v ← vector(1, 0, 0)
// Then magnitude(v) = 1
// Chapter 1. Tuples, Points, and Vectors • 8
// report erratum • discuss
// Scenario: Computing the magnitude of vector(0, 1, 0)
// Given v ← vector(0, 1, 0)
// Then magnitude(v) = 1
// Scenario: Computing the magnitude of vector(0, 0, 1)
// Given v ← vector(0, 0, 1)
// Then magnitude(v) = 1
// Scenario: Computing the magnitude of vector(1, 2, 3)
// Given v ← vector(1, 2, 3)
// Then magnitude(v) = √14
// Scenario: Computing the magnitude of vector(-1, -2, -3)
// Given v ← vector(-1, -2, -3)
// Then magnitude(v) = √14

// ********* Normalization *********
// Scenario: Normalizing vector(4, 0, 0) gives (1, 0, 0)
// Given v ← vector(4, 0, 0)
// Then normalize(v) = vector(1, 0, 0)

// Scenario: Normalizing vector(1, 2, 3)
// Given v ← vector(1, 2, 3)
// # vector(1/√14, 2/√14, 3/√14)
// Then normalize(v) = approximately vector(0.26726, 0.53452, 0.80178)

// Scenario: The magnitude of a normalized vector
// Given v ← vector(1, 2, 3)
// When norm ← normalize(v)
// Then magnitude(norm) = 1

// ********* Dot Product *********
// Scenario: The dot product of two tuples
// Given a ← vector(1, 2, 3)
// And b ← vector(2, 3, 4)
// Then dot(a, b) = 20

// function dot(a, b)
// return a.x * b.x +
// a.y * b.y +
// a.z * b.z +
// a.w * b.w
// end function

// ********* Cross Product *********

// Scenario: The cross product of two vectors
// Given a ← vector(1, 2, 3)
// And b ← vector(2, 3, 4)
// Then cross(a, b) = vector(-1, 2, -1)
// And cross(b, a) = vector(1, -2, 1)

// function cross(a, b)
// return vector(a.y * b.z - a.z * b.y,
// a.z * b.x - a.x * b.z,
// a.x * b.y - a.y * b.x)
// end function

// ********* Putting It Together *********

// function tick(env, proj)
// position ← proj.position + proj.velocity
// velocity ← proj.velocity + env.gravity + env.wind
// return projectile(position, velocity)
// end function

// # projectile starts one unit above the origin.
// # velocity is normalized to 1 unit/tick.
// p ← projectile(point(0, 1, 0), normalize(vector(1, 1, 0)))
// # gravity -0.1 unit/tick, and wind is -0.01 unit/tick.
// e ← environment(vector(0, -0.1, 0), vector(-0.01, 0, 0))


// ********* Representing Colors *********
// Scenario: Colors are (red, green, blue) tuples
// Given c ← color(-0.5, 0.4, 1.7)
// Then c.red = -0.5
// And c.green = 0.4
// And c.blue = 1.7

// ********* Implementing Color Operations *********
// Scenario: Adding colors
// Given c1 ← color(0.9, 0.6, 0.75)
// And c2 ← color(0.7, 0.1, 0.25)
// Then c1 + c2 = color(1.6, 0.7, 1.0)

// Scenario: Subtracting colors
// Given c1 ← color(0.9, 0.6, 0.75)
// And c2 ← color(0.7, 0.1, 0.25)
// Then c1 - c2 = color(0.2, 0.5, 0.5)

// Scenario: Multiplying a color by a scalar
// Given c ← color(0.2, 0.3, 0.4)
// Then c * 2 = color(0.4, 0.6, 0.8)

// Scenario: Multiplying colors
// Given c1 ← color(1, 0.2, 0.4)
// And c2 ← color(0.9, 1, 0.1)
// Then c1 * c2 = color(0.9, 0.2, 0.04)

// function hadamard_product(c1, c2)
// r ← c1.red * c2.red
// g ← c1.green * c2.green
// b ← c1.blue * c2.blue
// return color(r, g, b)
// end function

// ********* Creating a Canvas *********

// Scenario: Creating a canvas
// Given c ← canvas(10, 20)
// Then c.width = 10
// And c.height = 20
// And every pixel of c is color(0, 0, 0)

// Scenario: Writing pixels to a canvas
// Given c ← canvas(10, 20)
// And red ← color(1, 0, 0)
// When write_pixel(c, 2, 3, red)
// Then pixel_at(c, 2, 3) = red

// ********* Saving a Canvas *********
// Scenario: Constructing the PPM header
// Given c ← canvas(5, 3)
// When ppm ← canvas_to_ppm(c)
// 1. netpbm.sourceforge.net
// Chapter 2. Drawing on a Canvas • 20
// report erratum • discuss
// Then lines 1-3 of ppm are
// """
// P3
// 5 3
// 255
// """
// Scenario: Constructing the PPM pixel data
// Given c ← canvas(5, 3)
// And c1 ← color(1.5, 0, 0)
// And c2 ← color(0, 0.5, 0)
// And c3 ← color(-0.5, 0, 1)
// When write_pixel(c, 0, 0, c1)
// And write_pixel(c, 2, 1, c2)
// And write_pixel(c, 4, 2, c3)
// And ppm ← canvas_to_ppm(c)
// Then lines 4-6 of ppm are
// """
// 255 0 0 0 0 0 0 0 0 0 0 0 0 0 0
// 0 0 0 0 0 0 0 128 0 0 0 0 0 0 0
// 0 0 0 0 0 0 0 0 0 0 0 0 0 0 255
// """

// Scenario: Splitting long lines in PPM files
// Given c ← canvas(10, 2)
// When every pixel of c is set to color(1, 0.8, 0.6)
// And ppm ← canvas_to_ppm(c)
// Then lines 4-7 of ppm are
// """
// 255 204 153 255 204 153 255 204 153 255 204 153 255 204 153 255 204
// 153 255 204 153 255 204 153 255 204 153 255 204 153
// 255 204 153 255 204 153 255 204 153 255 204 153 255 204 153 255 204
// 153 255 204 153 255 204 153 255 204 153 255 204 153
// """

// Scenario: PPM files are terminated by a newline character
// Given c ← canvas(5, 3)
// When ppm ← canvas_to_ppm(c)
// Then ppm ends with a newline character

// ********* Putting It Together *********
// start ← point(0, 1, 0)
// velocity ← normalize(vector(1, 1.8, 0)) * 11.25
// p ← projectile(start, velocity)
// gravity ← vector(0, -0.1, 0)
// wind ← vector(-0.01, 0, 0)
// e ← environment(gravity, wind)
// c ← canvas(900, 550)

// *********  *********

// *********  *********

// *********  *********