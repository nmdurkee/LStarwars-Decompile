/* Ghidra pseudocode, not original source.
 * ev_e165dd79ce50f74ce872f7d9e4945159ab28a1cd27d81db1142f7150b3bed141
 * Entry: 0x629480; label: FUN_00629480
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00629480(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_2 + 0xc);
  if (iVar1 != 0) {
    FUN_006279b0(param_1,iVar1);
    *(int *)(iVar1 + 0x14) = *(int *)(param_2 + 0x1c) + 10;
    *(undefined4 *)(iVar1 + 0x18) = 0x32;
    iVar2 = DAT_00973904 * 2 - *(int *)(iVar1 + 0x20);
    if (0x31 < iVar2) {
      iVar2 = 0x32;
    }
    *(int *)(iVar1 + 0x18) = iVar2;
  }
  *(byte *)(param_2 + 0x11) = *(byte *)(param_2 + 0x11) & 0xfe;
  return;
}

