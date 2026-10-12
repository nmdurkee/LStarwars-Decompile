/* Ghidra pseudocode, not original source.
 * ev_73619ddf1363e83d16290e31c370c9dcae9e0ef7a000d1118e2b2a74fc34e424
 * Entry: 0x6eb9a0; label: FID_conflict:_cos
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Multiple Matches With Different Base Names
    _acos
    _asin
    _atan
    _cos
     8 names - too many to list
   
   Libraries: Visual Studio 2003, Visual Studio 2005, Visual Studio 2008 */

double __cdecl FID_conflict__cos(double _X)

{
  ushort in_FPUControlWord;
  float10 fVar1;
  
  if ((DAT_029a9c44 != 0) && ((MXCSR & 0x1f80) == 0x1f80 && (in_FPUControlWord & 0x7f) == 0x7f)) {
    fVar1 = (float10)FUN_006fc948();
    return (double)fVar1;
  }
                    /* WARNING: Subroutine does not return */
  __fload_withFB();
}

