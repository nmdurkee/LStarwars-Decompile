/* Ghidra analysis pseudocode, not original source.
 * ev_7cb997f3f06904df49554a3614ea3c2031937e13b6d92041b838b169c363bf2a
 * Entry: 0x5f7d00; label: FUN_005f7d00
 */

void FUN_005f7d00(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  
  switch(param_2) {
  case 0:
    iVar1 = 0;
    break;
  case 1:
    iVar1 = 1;
    break;
  case 2:
    iVar1 = 2;
    break;
  case 3:
    iVar1 = 3;
    break;
  default:
    iVar1 = -1;
  }
  *(uint *)(param_1 + 0x20) =
       *(uint *)(param_1 + 0x20) ^ (iVar1 << 0x11 ^ *(uint *)(param_1 + 0x20)) & 0xe0000;
  switch(param_3) {
  case 0:
    iVar1 = 0;
    break;
  case 1:
    iVar1 = 1;
    break;
  case 2:
    iVar1 = 2;
    break;
  case 3:
    iVar1 = 3;
    break;
  default:
    iVar1 = -1;
  }
  uVar2 = (iVar1 << 0x14 ^ *(uint *)(param_1 + 0x20)) & 0x700000 ^ *(uint *)(param_1 + 0x20);
  *(uint *)(param_1 + 0x20) = uVar2;
  switch(param_4) {
  case 0:
    *(uint *)(param_1 + 0x20) = uVar2 & 0x3800000 ^ uVar2;
    return;
  case 1:
    *(uint *)(param_1 + 0x20) = (uVar2 ^ 0x800000) & 0x3800000 ^ uVar2;
    return;
  case 2:
    *(uint *)(param_1 + 0x20) = (uVar2 ^ 0x1000000) & 0x3800000 ^ uVar2;
    return;
  case 3:
    *(uint *)(param_1 + 0x20) = (uVar2 ^ 0x1800000) & 0x3800000 ^ uVar2;
    return;
  default:
    *(uint *)(param_1 + 0x20) = (uVar2 ^ 0xff800000) & 0x3800000 ^ uVar2;
    return;
  }
}

