/* Ghidra pseudocode, not original source.
 * ev_51f4537ed7c57c9a0fa7f304a7a0f3427cc608dfecd65a4b8280241ed2e1f797
 * Entry: 0x5ab950; label: FUN_005ab950
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_005ab950(int *param_1,uint param_2,byte param_3)

{
  int iVar1;
  
  if ((param_1 == (int *)0x0) || (iVar1 = *param_1, iVar1 == 0)) {
    return 0;
  }
  if ((param_3 & 1) == 0) {
    *(ushort *)(iVar1 + 0x13a) =
         *(ushort *)(iVar1 + 0x13a) ^ (byte)((param_2 == 0) * '\x02' ^ *(byte *)(iVar1 + 0x13a)) & 2
    ;
    return 1;
  }
  if ((*(ushort *)(iVar1 + 0x13a) & 2) != 0) {
    return param_2;
  }
  *(ushort *)(iVar1 + 0x13a) = *(ushort *)(iVar1 + 0x13a) & 0xffef;
  return (uint)(param_2 == 0);
}

