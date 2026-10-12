/* Ghidra pseudocode, not original source.
 * ev_35392dc412ffe2b2a558f5a6ba3fa7479ff279a31c4c87c94d67c76968103d24
 * Entry: 0x6165f0; label: FUN_006165f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006165f0(undefined4 param_1,int param_2,int param_3,int param_4,undefined4 param_5,
                 undefined4 param_6)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int in_ECX;
  undefined1 auStack_108 [3];
  undefined1 local_105 [257];
  uint local_4;
  
  uVar2 = param_6;
  local_4 = DAT_00829570 ^ (uint)auStack_108;
  bVar1 = false;
  do {
    if (param_2 != 0) {
      FUN_004ef660(local_105,param_2 + param_3,1);
      param_3 = param_3 + 1;
    }
    switch(local_105[0]) {
    case 0:
      if ((*(int *)(in_ECX + 0xc) == 0) || (iVar3 = FUN_00612950(uVar2), iVar3 == 0))
      goto switchD_0061665f_default;
      FUN_00580dd0(in_ECX + 0x28);
      break;
    case 1:
      if ((*(int *)(in_ECX + 0xc) == 0) || (iVar3 = FUN_00612910(uVar2), iVar3 == 0))
      goto switchD_0061665f_default;
      FUN_00613de0(&param_1,uVar2);
      break;
    case 2:
      if ((*(int *)(in_ECX + 0xc) == 0) || (iVar3 = FUN_00612910(uVar2), iVar3 == 0))
      goto switchD_0061665f_default;
      FUN_00613f40(&param_1,uVar2);
      break;
    case 3:
      if ((*(int *)(in_ECX + 0xc) == 0) || (iVar3 = FUN_00612950(uVar2), iVar3 == 0))
      goto switchD_0061665f_default;
      FUN_00616440(&param_1,uVar2);
      break;
    case 4:
      if ((*(int *)(in_ECX + 0xc) == 0) || (iVar3 = FUN_00612950(uVar2), iVar3 == 0))
      goto switchD_0061665f_default;
      FUN_00616510(&param_1,uVar2);
      break;
    case 5:
      if ((*(int *)(in_ECX + 0xc) == 0) || (iVar3 = FUN_00612950(uVar2), iVar3 == 0))
      goto switchD_0061665f_default;
      FUN_00614120(&param_1,uVar2);
      break;
    case 6:
      if ((*(int *)(in_ECX + 0xc) == 0) || (iVar3 = FUN_00612950(uVar2), iVar3 == 0))
      goto switchD_0061665f_default;
      FUN_006141b0(&param_1,uVar2);
      break;
    case 7:
      if ((*(int *)(in_ECX + 0xc) == 0) || (iVar3 = FUN_00612950(uVar2), iVar3 == 0))
      goto switchD_0061665f_default;
      FUN_00614290(&param_1,uVar2);
      break;
    case 8:
      if ((*(int *)(in_ECX + 0xc) == 0) || (iVar3 = FUN_00612950(uVar2), iVar3 == 0))
      goto switchD_0061665f_default;
      FUN_006142f0(&param_1,uVar2);
      break;
    case 9:
      FUN_006158c0(&param_1,uVar2);
      break;
    case 10:
      FUN_00612df0(&param_1,uVar2);
      break;
    case 0xb:
      FUN_006144f0(&param_1,uVar2);
      break;
    case 0xc:
      if ((*(int *)(in_ECX + 0xc) == 0) || (iVar3 = FUN_00612950(uVar2), iVar3 == 0))
      goto switchD_0061665f_default;
      FUN_00614450(&param_1,uVar2);
      break;
    default:
switchD_0061665f_default:
      bVar1 = true;
    }
    if (param_2 == 0) goto LAB_00616891;
  } while ((param_4 != param_3 && -1 < param_4 - param_3) && (!bVar1));
  if (*(uint *)(param_2 + 0x4b0) < 2) {
    *(undefined4 *)(param_2 + 0x4b0) = 0;
  }
  else {
    *(uint *)(param_2 + 0x4b0) = *(uint *)(param_2 + 0x4b0) - 1;
  }
LAB_00616891:
  __security_check_cookie(local_4 ^ (uint)auStack_108);
  return;
}

