
/*!
\ingroup PkgVisibility_2Concepts
\cgalConcept

A model of the `Visibility_2` concept can be attached to an `Arrangement_2` instance to 
answer visibility queries within the faces of this arrangement.

\cgalHasModel `CGAL::Simple_polygon_visibility_2`
\cgalHasModel `CGAL::Rotational_sweep_visibility_2`
\cgalHasModel `CGAL::Triangular_expansion_visibility_2`

*/
class Visibility_2 {
public:

/// \name Types 
/// @{
  
 /*! 
   The arrangement type of the input.
 */ 
  typedef unspecified_type Arrangement_2;  

 /*! 
   The 2D point type used for the queries. 
 */ 
  typedef Arrangement_2::Point_2 Point_2;

  /*!
   * The face handle type of the input arrangement.
   */
  typedef Arrangement_2::Face_const_handle Face_const_handle;

  /*!
   * The halfedge handle type of the input arrangement.
   */
  typedef Arrangement_2::Halfedge_const_handle Halfedge_const_handle;

/// @}

/// \name Tags 
/// @{
  /*! 
    Tag identifying whether the regularized visibility area is computed (either \ref CGAL::Tag_true or \ref CGAL::Tag_false). 
  */
  typedef unspecified_type Regularization_tag;
  
  /*! 
    Tag identifying whether general polygons (with holes) are supported (either \ref CGAL::Tag_true or \ref CGAL::Tag_false). 
  */
  typedef unspecified_type Supports_general_polygon_tag; 

  /*! 
    Tag identifying whether general simple polygons are supported (either \ref CGAL::Tag_true or \ref CGAL::Tag_false). 
  */
  typedef unspecified_type Supports_simple_polygon_tag; 
/// @}

/// \name Constructors 
/// @{

/*! 
Default constructor creates an empty `Visibility_2` object that is not
attached to any arrangement yet.
*/ 
Visibility_2(); 

/*! 
Constructs a `Visibility_2` object that is attached to `arr`.
*/ 
Visibility_2(const Arrangement_2& arr);

/// @}


/// \name Functions 
/// @{

/*!
Returns whether an arrangement is attached to the visibility object
*/
  bool is_attached() const;

/*!
Attaches the given arrangement `arr` to the visibility object.
In case the object is already attached to another arrangement, 
the visibility object gets detached before being attached to `arr`.
*/
  void attach(const Arrangement_2& arr);

  
/*!
Detaches the arrangement from the visibility object it is currently attached to
*/
  void detach();

/*!
Access to the attached arrangement
*/
  const Arrangement_2& arr() const;

/*! 
Computes the visibility region for the given query point `q` in the
face \f$ f \f$ of the arrangement that is attached to the visibility object.
The visibility region of `q` is stored in `out_arr`, that is, 
all features but the unbounded face of `out_arr` represent the visibility region. 

\tparam VisibilityArrangement_2 is the type of the output arrangement representing the visibility polygon.
It must be an instance of CGAL::Arrangement_2, where its CGAL::Arrangement_2::Traits_2 
must be mutual convertible to Visibility_2::Traits_2. 

\param q is the query point
\param f is the face of the arrangement in which the visibility region is computed
\param out_arr is the output arrangement 
\pre `f` is a face of  `this->arr()`
\pre `q` is in the interior of the given face `f`
\return the face handle to the face in `out_arr` that represents interior of the visibility region
*/ 
  template <typename VisibilityArrangement_2> 
  typename Visibility_arrangement_2::Face_handle 
  compute_visibility(const Point_2& q, const Face_const_handle f, VisibilityArrangement_2& out_arr) const;

/*!
Computes the visibility region in `e->face()` for the given query 
point `q` which must be located on `e`. 
If `q` is an interior point of `e`, the computed visibility 
region is restricted to the side indicated by the halfedge `e`.
If `q` is an endpoint of `e`, the visibility region is restricted by `e` and `e->next()`.
The visibility region of `q` is stored in `out_arr`, that is, 
all features but the unbounded face of `out_arr` represent the visibility region.

\tparam VisibilityArrangement_2 is the type of the output arrangement representing the visibility polygon.
It must be an instance of CGAL::Arrangement_2, where its CGAL::Arrangement_2::Traits_2 
must be mutual convertible to Visibility_2::Traits_2.
\param q is the query point
\param e the halfedge on which `q` is located
\param out_arr is the output arrangement
\pre `e` is a halfedge of `this->arr()`
\pre `q` is on `e`
\pre `q` equals to `e->target()->point()` if `q` is an endpoint of `e`
\return a handle to the face in `out_arr` that represents the interior of the visibility region
*/
  template <typename VisibilityArrangement_2> 
  typename Visibility_arrangement_2::Face_handle 
  compute_visibility(const Point_2& q, const Halfedge_const_handle e, Visibility_arrangement_2& out_arr) const;

/// @}

}; /* end Visibility_2 */

