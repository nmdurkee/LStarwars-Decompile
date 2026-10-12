/* Ghidra analysis pseudocode, not original source.
 * ev_7cb997f3f06904df49554a3614ea3c2031937e13b6d92041b838b169c363bf2a
 * Entry: 0x5f7ed0; label: FUN_005f7ed0
 */

void FUN_005f7ed0(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  
  switch(param_2) {
  case 0:
    iVar2 = 1;
    break;
  case 1:
    iVar2 = 2;
    break;
  case 2:
    iVar2 = 3;
    break;
  case 3:
    iVar2 = 4;
    break;
  default:
    iVar2 = -1;
  }
  *(uint *)(param_1 + 0x20) =
       *(uint *)(param_1 + 0x20) ^ (iVar2 << 8 ^ *(uint *)(param_1 + 0x20)) & 0x700;
  uVar1 = *(uint *)(param_1 + 0x20);
  switch(param_3) {
  case 0:
    *(uint *)(param_1 + 0x20) = (uVar1 ^ 0x800) & 0x3800 ^ uVar1;
    return;
  case 1:
    *(uint *)(param_1 + 0x20) = (uVar1 ^ 0x1000) & 0x3800 ^ uVar1;
    return;
  case 2:
    *(uint *)(param_1 + 0x20) = (uVar1 ^ 0x1800) & 0x3800 ^ uVar1;
    return;
  case 3:
    *(uint *)(param_1 + 0x20) = (uVar1 ^ 0x2000) & 0x3800 ^ uVar1;
    return;
  default:
    *(uint *)(param_1 + 0x20) = (uVar1 ^ 0xfffff800) & 0x3800 ^ uVar1;
    return;
  }
}

