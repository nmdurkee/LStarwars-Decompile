/* Ghidra pseudocode, not original source.
 * ev_21d1b4024f0628b99911cc952efca6864ea092f4299a0ea9bb41a534640658fb
 * Entry: 0x46c400; label: FUN_0046c400
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0046c400(int param_1,undefined4 param_2)

{
  char cVar1;
  undefined1 local_c [12];
  
  cVar1 = *(char *)(param_1 + 0x107f);
  if (('\0' < cVar1) &&
     (((int)cVar1 < (int)(uint)*(byte *)(param_1 + 0x107e) ||
      (('\0' < cVar1 && ((int)cVar1 < (int)(uint)*(byte *)(param_1 + 0x107e))))))) {
    *(char *)(param_1 + 0x107f) = cVar1 + '\x01';
  }
  if (*(byte *)(param_1 + 0xe39) < 4) {
    *(byte *)(param_1 + 0xe39) = *(byte *)(param_1 + 0xe39) + 1;
  }
  if ((*(uint *)(*(int *)(param_1 + 0x54) + 4) & 0x2000) == 0) {
    FUN_0062c560(*(undefined4 *)(PTR_DAT_00802c54 + 0x134),0xf,param_2);
  }
  else {
    FUN_005b3830(local_c,param_1 + 0x68,0x3f000000);
    FUN_0062c760(*(undefined4 *)(PTR_DAT_00802c54 + 0x134),0x10,param_2,0xf,local_c);
  }
  FUN_00547930(0x27,param_2,0,0);
  FUN_0054a8a0(**(undefined4 **)(param_1 + 0xca4),0x3dcccccd,0);
  return;
}

