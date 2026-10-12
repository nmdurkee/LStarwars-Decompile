/* Ghidra pseudocode, not original source.
 * ev_6521300b9938a199c527bda86aad79e1bd40e1a48847beae11455f6dd9ad37ba
 * Entry: 0x623d40; label: FUN_00623d40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00623d40(undefined4 *param_1)

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

