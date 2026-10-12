/* Ghidra analysis pseudocode, not original source.
 * ev_b66c424cb3575f57780fb90d996a1c84f19feddd26ab04bda15cdd4040b17690
 * Entry: 0x4ffb20; label: FUN_004ffb20
 */

void FUN_004ffb20(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  LARGE_INTEGER local_8;
  
  QueryPerformanceCounter(&local_8);
  if ((DAT_009209e4 <= local_8.s.HighPart) &&
     ((DAT_009209e4 < local_8.s.HighPart || (DAT_009209e0 < local_8.s.LowPart)))) {
    bVar3 = local_8.s.LowPart < DAT_009209e0;
    iVar1 = local_8.s.HighPart - DAT_009209e4;
    *param_1 = local_8.s.LowPart - DAT_009209e0;
    *param_2 = iVar1 - (uint)bVar3;
    return;
  }
  iVar2 = -DAT_009209e0;
  iVar1 = 0x7fffffff - DAT_009209e4;
  *param_1 = local_8.s.LowPart + (iVar2 - 1U);
  *param_2 = local_8.s.HighPart + iVar1 + (uint)CARRY4(local_8.s.LowPart,iVar2 - 1U);
  return;
}

