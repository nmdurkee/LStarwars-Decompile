/* Ghidra analysis pseudocode, not original source.
 * ev_95f339e64e03912db0b4337524e50c5f1fa1cc6c36f27950d42195022949d97c
 * Entry: 0x594810; label: FUN_00594810
 */

void FUN_00594810(int *param_1,int param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  short *psVar2;
  
  iVar1 = 0;
  if (*(ushort *)((int)param_1 + 6) != 0) {
    psVar2 = (short *)*param_1;
    while (*psVar2 != param_2) {
      iVar1 = iVar1 + 1;
      psVar2 = psVar2 + 0xe;
      if ((int)(uint)*(ushort *)((int)param_1 + 6) <= iVar1) {
        return;
      }
    }
    *param_3 = *(undefined4 *)((short *)*param_1 + iVar1 * 0xe + 10);
    *param_4 = *(undefined4 *)(*param_1 + 0x18 + iVar1 * 0x1c);
  }
  return;
}

