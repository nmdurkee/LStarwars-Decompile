/* Ghidra pseudocode, not original source.
 * ev_fb6cd954323bef10c706b5185a175772da5bd325e62fab563c9169acbcfebd41
 * Entry: 0x613de0; label: FUN_00613de0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00613de0(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int in_ECX;
  int iVar2;
  short local_110 [2];
  short local_10c [2];
  short local_108 [2];
  undefined1 local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_110;
  if (param_1[1] != 0) {
    FUN_004ef660(local_110,param_1[2] + param_1[1],2);
    if (*param_1 != 0) {
      FUN_00621180(local_110);
    }
    param_1[2] = param_1[2] + 2;
  }
  if (param_1[1] != 0) {
    FUN_004ef660(local_108,param_1[2] + param_1[1],2);
    if (*param_1 != 0) {
      FUN_00621180(local_108);
    }
    param_1[2] = param_1[2] + 2;
  }
  if (param_1[1] != 0) {
    FUN_004ef660(local_10c,param_1[2] + param_1[1],2);
    if (*param_1 != 0) {
      FUN_00621180(local_10c);
    }
    param_1[2] = param_1[2] + 2;
  }
  if ((0 < local_10c[0]) && (param_1[1] != 0)) {
    iVar2 = (int)local_10c[0];
    FUN_004ef660(local_104,param_1[2] + param_1[1],iVar2);
    param_1[2] = param_1[2] + iVar2;
  }
  iVar2 = FUN_006be7f0((int)local_108[0]);
  if (*(int *)(in_ECX + 0xc + (local_110[0] * 3 + 6) * 8) == 0) {
    uVar1 = FUN_006c6330(*(undefined4 *)(iVar2 + 0x14),local_104,(int)local_10c[0],(int)local_110[0]
                         ,1);
    FUN_00611e00((int)local_110[0],uVar1,iVar2,param_2,0);
  }
  __security_check_cookie(local_4 ^ (uint)local_110);
  return;
}

