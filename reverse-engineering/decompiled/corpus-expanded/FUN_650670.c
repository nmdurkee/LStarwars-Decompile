/* Ghidra pseudocode, not original source.
 * ev_f26efce709548f397f112d14bef56d8f0f3486015c16e671b302622d1d4cb319
 * Entry: 0x650670; label: FUN_00650670
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00650670(int param_1,uint param_2)

{
  ushort *puVar1;
  int iVar2;
  
  if ((param_2 < 0x640) &&
     (iVar2 = (int)(param_2 + ((int)param_2 >> 0x1f & 0xfU)) >> 4, iVar2 < 100)) {
    puVar1 = (ushort *)(param_1 + iVar2 * 2);
    *puVar1 = *puVar1 | (ushort)(1 << ((byte)param_2 & 0xf));
  }
  return;
}

