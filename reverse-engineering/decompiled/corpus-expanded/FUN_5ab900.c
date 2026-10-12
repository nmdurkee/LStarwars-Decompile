/* Ghidra pseudocode, not original source.
 * ev_51f4537ed7c57c9a0fa7f304a7a0f3427cc608dfecd65a4b8280241ed2e1f797
 * Entry: 0x5ab900; label: FUN_005ab900
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005ab900(int *param_1,int param_2)

{
  int iVar1;
  
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1;
    *(ushort *)(iVar1 + 0x13a) =
         *(ushort *)(iVar1 + 0x13a) ^ (byte)((param_2 != 0) * '\x02' ^ *(byte *)(iVar1 + 0x13a)) & 2
    ;
    if ((*(ushort *)(iVar1 + 0x13a) & 2) != 0) {
      *(ushort *)(iVar1 + 0x13a) = *(ushort *)(iVar1 + 0x13a) & 0xffcf;
      *(undefined1 *)(iVar1 + 0x132) = 0;
    }
  }
  return;
}

