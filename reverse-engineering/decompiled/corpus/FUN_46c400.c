/* Ghidra analysis pseudocode, not original source.
 * ev_55017b0be5ecbbe7992f90db1bd4d4788b50f0daee2843c81c8d7e89602b0f77
 * Entry: 0x46c400; label: FUN_0046c400
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

