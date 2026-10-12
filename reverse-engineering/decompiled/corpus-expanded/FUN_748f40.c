/* Ghidra pseudocode, not original source.
 * ev_e0447f8e73d2150c5385a8aa294440164da99c01f5f62ba5bd70b4e5b4546b39
 * Entry: 0x748f40; label: FUN_00748f40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00748f40(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  undefined4 uVar2;
  
  switch(param_2) {
  case 0:
    FUN_00748b10(param_3);
    return;
  case 2:
    uVar1 = *(uint *)(param_1 + 0x6c);
    FUN_00748ad0((float)(uVar1 & 0xff) / 255.0,(float)((int)uVar1 >> 8 & 0xff) / 255.0,
                 (float)((int)uVar1 >> 0x10 & 0xff) / 255.0,*(undefined4 *)(param_1 + 0x100));
    return;
  case 9:
    if (*(char *)(param_1 + 0x47) == '\0') {
      uVar2 = 0;
    }
    else {
      uVar2 = 0x3f800000;
    }
    FUN_00748a80(uVar2);
    return;
  case 10:
    FUN_00748ad0(*(undefined4 *)(param_1 + 0x80),0,*(undefined4 *)(param_1 + 0x84),
                 *(undefined4 *)(param_1 + 0x98));
    return;
  case 0xb:
    FUN_00748ad0(*(undefined4 *)(param_1 + 0x3c),0,0,0);
    return;
  case 0xc:
    FUN_00748ad0(*(undefined4 *)(param_1 + 0x7c),*(undefined4 *)(param_1 + 0x78),
                 *(undefined4 *)(param_1 + 0x90),*(undefined4 *)(param_1 + 0x94));
    return;
  case 0xd:
    FUN_00748ad0(*(undefined4 *)(param_1 + 0x88),*(undefined4 *)(param_1 + 0x8c),0,0);
    return;
  case 0xf:
    FUN_00748a80(*(undefined4 *)(param_1 + 100));
    return;
  case 0x10:
    FUN_00748ad0(*(undefined4 *)(param_1 + 0x104),*(undefined4 *)(param_1 + 0x108),0,0);
    break;
  case 0x33:
    FUN_00748b10(param_3);
    return;
  case 0x34:
    FUN_00748b10(param_3);
    return;
  case 0x35:
    FUN_00748b10(param_3);
    return;
  case 0x36:
    FUN_00748b10(param_3);
    return;
  case 0x37:
    FUN_00748ad0(*(undefined4 *)(param_1 + 0x24),*(undefined4 *)(param_1 + 0x28),
                 *(undefined4 *)(param_1 + 0x2c),*(undefined4 *)(param_1 + 0x30));
    return;
  case 0x39:
    FUN_00748b10(param_3);
    return;
  case 0x3b:
    FUN_00748b10(param_3);
    return;
  case 0x3c:
    FUN_00748a80((*(float *)(param_1 + 0x9c) - 1.0) * 0.1);
    return;
  case 0x40:
    FUN_00748aa0(param_3);
    return;
  case 0x41:
    FUN_00748aa0(param_3);
    return;
  case 0x42:
    FUN_00748aa0(param_3);
    return;
  case 0x43:
    FUN_00748aa0(param_3);
    return;
  }
  return;
}

