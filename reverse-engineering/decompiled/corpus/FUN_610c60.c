/* Ghidra analysis pseudocode, not original source.
 * ev_11d21a68175a6094cc049e5bf26b7ff6a5a52d03a1d985acdd25f24f4e0bcb10
 * Entry: 0x610c60; label: FUN_00610c60
 */

void FUN_00610c60(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x20) = param_1;
  switch(param_1) {
  case 0:
    *(undefined4 *)(in_ECX + 0x24) = 0;
    *(undefined4 *)(in_ECX + 0x14) = 0;
    *(undefined4 *)(in_ECX + 0x18) = 0;
    return;
  case 1:
    *(undefined4 *)(in_ECX + 0x24) = 1;
    *(undefined4 *)(in_ECX + 0x34) = 0x3ba3d70a;
    *(undefined4 *)(in_ECX + 0x14) = 0x14;
    *(undefined4 *)(in_ECX + 0x18) = 0x28;
    return;
  case 2:
    *(undefined4 *)(in_ECX + 0x24) = 1;
    *(undefined4 *)(in_ECX + 0x34) = 0x3ca3d70a;
    *(undefined4 *)(in_ECX + 0x14) = 0x32;
    *(undefined4 *)(in_ECX + 0x18) = 0x46;
    return;
  case 3:
    *(undefined4 *)(in_ECX + 0x24) = 2;
    *(undefined4 *)(in_ECX + 0x34) = 0x3c23d70a;
    *(undefined4 *)(in_ECX + 0x28) = 5;
    *(undefined4 *)(in_ECX + 0x2c) = 0xf;
    *(undefined4 *)(in_ECX + 0x14) = 100;
    *(undefined4 *)(in_ECX + 0x18) = 0x78;
  }
  return;
}

