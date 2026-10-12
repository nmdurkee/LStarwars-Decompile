/* Ghidra analysis pseudocode, not original source.
 * ev_c05bc3de3023c0a6cb52f4e362146021e78fd9035a9b4ae5f12ca5d880999daa
 * Entry: 0x416c30; label: FUN_00416c30
 */

void FUN_00416c30(void)

{
  undefined4 uVar1;
  int in_EAX;
  
  *(undefined1 *)(in_EAX + 0x285) = 0;
  *(undefined1 *)(in_EAX + 0xe42) = 0;
  *(undefined4 *)(in_EAX + 0xf24) = DAT_00802500;
  *(undefined4 *)(in_EAX + 0xf28) = DAT_00802504;
  uVar1 = DAT_00802508;
  *(undefined4 *)(in_EAX + 0x220) = 0x49f42400;
  *(undefined4 *)(in_EAX + 0xf2c) = uVar1;
  *(undefined4 *)(in_EAX + 0x224) = 0x49f42400;
  *(undefined1 *)(in_EAX + 0x283) = 0xff;
  *(undefined1 *)(in_EAX + 0x284) = 0xff;
  *(undefined2 *)(in_EAX + 0x106c) = 0xffff;
  return;
}

