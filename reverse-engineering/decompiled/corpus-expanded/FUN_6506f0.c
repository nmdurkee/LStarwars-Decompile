/* Ghidra pseudocode, not original source.
 * ev_f26efce709548f397f112d14bef56d8f0f3486015c16e671b302622d1d4cb319
 * Entry: 0x6506f0; label: FUN_006506f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_006506f0(int param_1,uint param_2)

{
  int iVar1;
  
  if ((param_2 < 0x640) &&
     (iVar1 = (int)(param_2 + ((int)param_2 >> 0x1f & 0xfU)) >> 4, iVar1 < 100)) {
    return (uint)((1 << ((byte)param_2 & 0xf) & *(ushort *)(param_1 + iVar1 * 2)) != 0);
  }
  return 0xffffffff;
}

