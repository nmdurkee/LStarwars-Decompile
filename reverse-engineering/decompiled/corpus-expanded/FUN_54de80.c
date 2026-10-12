/* Ghidra pseudocode, not original source.
 * ev_5bb5b933382fccff1624478c543279b7c4a11e7bde078056255cfa1f5dfacd26
 * Entry: 0x54de80; label: FUN_0054de80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0054de80(int *param_1,int param_2)

{
  int iVar1;
  
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1;
    *(byte *)(iVar1 + 0x1e) = *(byte *)(iVar1 + 0x1e) ^ (param_2 != 0 ^ *(byte *)(iVar1 + 0x1e)) & 1
    ;
    if ((*(byte *)(iVar1 + 0x1e) & 1) != 0) {
      *(undefined4 *)(iVar1 + 0x58) = 0x3f800000;
    }
  }
  return;
}

