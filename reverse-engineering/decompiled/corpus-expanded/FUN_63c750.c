/* Ghidra pseudocode, not original source.
 * ev_0e84ad542db3be7599677a500db2c2fcd5f6f463504cd13a52c31f7d7facbfa7
 * Entry: 0x63c750; label: FUN_0063c750
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0063c750(undefined4 *param_1)

{
  undefined4 *in_EAX;
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_50 [19];
  
  local_60 = *param_1;
  local_5c = param_1[1];
  local_58 = param_1[2];
  local_70 = param_1[9];
  local_6c = param_1[10];
  local_68 = param_1[0xb];
  if (in_EAX != (undefined4 *)0x0) {
    if (((uint)in_EAX & 0xf) != 0) {
      puVar2 = local_50;
      for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar2 = *in_EAX;
        in_EAX = in_EAX + 1;
        puVar2 = puVar2 + 1;
      }
      in_EAX = local_50;
    }
    FUN_005b30a0(&local_60,&local_60,in_EAX);
    FUN_005b30a0(&local_70,&local_70,in_EAX);
  }
  FUN_005dc050(local_60,local_5c,local_58,local_70,local_6c,local_68,param_1[6]);
  return;
}

