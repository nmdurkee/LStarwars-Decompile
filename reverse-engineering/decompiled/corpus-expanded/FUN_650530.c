/* Ghidra pseudocode, not original source.
 * ev_f26efce709548f397f112d14bef56d8f0f3486015c16e671b302622d1d4cb319
 * Entry: 0x650530; label: FUN_00650530
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_00650530(uint param_1)

{
  int iVar1;
  
  if ((param_1 < 0x640) &&
     (iVar1 = (int)(param_1 + ((int)param_1 >> 0x1f & 0xfU)) >> 4, iVar1 < 100)) {
    return (uint)((1 << ((byte)param_1 & 0xf) & (&DAT_02921760)[iVar1]) != 0);
  }
  return 0xffffffff;
}

