/* Ghidra pseudocode, not original source.
 * ev_51f4537ed7c57c9a0fa7f304a7a0f3427cc608dfecd65a4b8280241ed2e1f797
 * Entry: 0x5ab9f0; label: FUN_005ab9f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005ab9f0(int *param_1,int param_2)

{
  int iVar1;
  
  if ((param_1 != (int *)0x0) && (iVar1 = *param_1, iVar1 != 0)) {
    FUN_005a15e0(*(undefined4 *)(iVar1 + 0x18),param_2);
    *(ushort *)(iVar1 + 0x13a) =
         *(ushort *)(iVar1 + 0x13a) ^ (byte)((param_2 != 0) * '\x04' ^ *(byte *)(iVar1 + 0x13a)) & 4
    ;
  }
  return;
}

