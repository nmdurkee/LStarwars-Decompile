/* Ghidra analysis pseudocode, not original source.
 * ev_fc46cff07f0ed537c3533760820ac45bd355561daa184f1b787f47d220e25ab8
 * Entry: 0x421100; label: FUN_00421100
 */

void FUN_00421100(char *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined1 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9,undefined4 param_10,int param_11)

{
  undefined4 uVar1;
  int in_ECX;
  int iVar2;
  int *piVar3;
  undefined1 local_404 [1024];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_404;
  if ((param_1 != (char *)0x0) && (*param_1 != '\0')) {
    FUN_0050c3e0(param_1,local_404);
    if (param_11 == 0) {
      uVar1 = FUN_00421050(local_404);
      uVar1 = FUN_006d6810(uVar1,param_2);
      param_11 = FUN_006d6810(uVar1,param_3);
    }
    iVar2 = 0;
    piVar3 = (int *)(in_ECX + 800);
    do {
      if (piVar3[-0x4a] == param_11) break;
      if (*piVar3 == param_11) {
        iVar2 = iVar2 + 1;
        break;
      }
      if (piVar3[0x4a] == param_11) {
        iVar2 = iVar2 + 2;
        break;
      }
      if (piVar3[0x94] == param_11) {
        iVar2 = iVar2 + 3;
        break;
      }
      if (piVar3[0xde] == param_11) {
        iVar2 = iVar2 + 4;
        break;
      }
      if (piVar3[0x128] == param_11) {
        iVar2 = iVar2 + 5;
        break;
      }
      iVar2 = iVar2 + 6;
      piVar3 = piVar3 + 0x1bc;
    } while (iVar2 < 0xc);
    if (iVar2 == 0xc) {
      iVar2 = 0;
      piVar3 = (int *)(in_ECX + 0x1f8);
      do {
        if (*piVar3 == 0) {
          *(undefined4 *)(iVar2 * 0x128 + 0x1d8 + in_ECX) = 0;
          *(int *)(iVar2 * 0x128 + in_ECX + 0x1f8) = param_11;
          break;
        }
        iVar2 = iVar2 + 1;
        piVar3 = piVar3 + 0x4a;
      } while (iVar2 < 0xc);
      if (iVar2 == 0xc) goto LAB_004212c0;
    }
    iVar2 = iVar2 * 0x128 + in_ECX;
    FUN_004f1f10(iVar2 + 0xd8,local_404);
    uVar1 = FUN_00420780(param_9,0x3f800000,param_8);
    *(undefined4 *)(iVar2 + 500) = uVar1;
    *(undefined4 *)(iVar2 + 0x1dc) = param_2;
    *(undefined1 *)(iVar2 + 0x1fc) = param_5;
    *(undefined4 *)(iVar2 + 0x1e0) = param_3;
    *(undefined1 *)(iVar2 + 0x1fd) = 1;
    *(undefined4 *)(iVar2 + 0x1e4) = param_4;
    *(undefined4 *)(iVar2 + 0x1e8) = param_6;
    *(undefined4 *)(iVar2 + 0x1ec) = param_7;
    *(undefined4 *)(iVar2 + 0x1f0) = param_10;
  }
LAB_004212c0:
  __security_check_cookie(local_4 ^ (uint)local_404);
  return;
}

