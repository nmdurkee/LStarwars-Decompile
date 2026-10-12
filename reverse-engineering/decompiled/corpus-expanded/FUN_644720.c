/* Ghidra pseudocode, not original source.
 * ev_347e1f77405e8535e9481480e28747f276aa6cf4478f7a28ab99ed1128324eac
 * Entry: 0x644720; label: FUN_00644720
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00644720(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_02920970;
  if (DAT_02920970 != 0) {
    iVar2 = FUN_006e6b90();
    *(float *)(iVar1 + 0xcc) = (float)iVar2;
  }
  return;
}

