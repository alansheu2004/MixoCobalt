!***********************************************************************
!*                   GNU Lesser General Public License
!*
!* This file is part of the GFDL Flexible Modeling System (FMS).
!*
!* FMS is free software: you can redistribute it and/or modify it under
!* the terms of the GNU Lesser General Public License as published by
!* the Free Software Foundation, either version 3 of the License, or (at
!* your option) any later version.
!*
!* FMS is distributed in the hope that it will be useful, but WITHOUT
!* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
!* FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
!* for more details.
!*
!* You should have received a copy of the GNU Lesser General Public
!* License along with FMS.  If not, see <http://www.gnu.org/licenses/>.
!***********************************************************************

subroutine MPP_TYPE_CREATE_(field, array_of_subsizes, array_of_starts, dtype)
    MPP_TYPE_, intent(in) :: field(:,:,:)
    integer, intent(in) :: array_of_subsizes(:)
    integer, intent(in) :: array_of_starts(:)
    type(mpp_type), target, intent(out) :: dtype

    if (.NOT. module_is_initialized) &
        call mpp_error(FATAL, 'MPP_TYPE_CREATE: You must first call mpp_init.')

    if (current_clock .NE. 0) &
        call SYSTEM_CLOCK(start_tick)

    call mpp_error(NOTE, 'MPP_TYPE_CREATE: &
                         &This function is not used in serial mode.')

    ! For consistency with the MPI version, we return a valid mpp_type
    dtype = mpp_byte

    if (current_clock .NE. 0) &
        call increment_current_clock(EVENT_TYPE_CREATE, MPP_TYPE_BYTELEN_)

end subroutine MPP_TYPE_CREATE_
