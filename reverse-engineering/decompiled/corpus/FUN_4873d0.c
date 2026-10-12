/* Ghidra analysis pseudocode, not original source.
 * ev_6a5348c5de1b6aa473bf814c408ae5ab94878b8c78b78ea0d14786caa34bcd70
 * Entry: 0x4873d0; label: FUN_004873d0
 */

undefined4 FUN_004873d0(int param_1,int param_2,int param_3)

{
  FUN_004a25b0(param_1,0);
  FUN_0058ff10(param_1,0);
  FUN_0059cb00(param_1);
  FUN_0055e4e0(param_1 + 0x6c4);
  if ((*(byte *)(param_1 + 0xeec) & 0x10) == 0) {
    FUN_0058d8e0(param_1);
  }
  *(int *)(param_1 + 0xcd0) = param_2;
  *(int *)(param_2 + 0xcd0) = param_1;
  *(undefined4 *)(param_1 + 0xea4) = 0;
  *(undefined4 *)(param_2 + 0xea4) = 0;
  *(int *)(param_1 + 0xcd4) = param_2;
  *(undefined1 *)(param_1 + 0x7b5) = 0x3b;
  FUN_00487270();
  *(undefined4 *)(param_1 + 0xdd0) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x748) = *(undefined4 *)(param_1 + 0x5c);
  *(undefined4 *)(param_1 + 0x74c) = *(undefined4 *)(param_1 + 0x60);
  *(undefined4 *)(param_1 + 0x750) = *(undefined4 *)(param_1 + 100);
  if (param_3 != 0) {
    FUN_0054a3e0(PTR_DAT_008021b4,0x3f000000,0,1);
  }
  FUN_0054a8a0(**(undefined4 **)(param_2 + 0xca4),0x3dcccccd,0);
  FUN_00549de0(PTR_DAT_008021b4,0x3dcccccd,0,0);
  FUN_00576960(0x28c);
  return 1;
}

