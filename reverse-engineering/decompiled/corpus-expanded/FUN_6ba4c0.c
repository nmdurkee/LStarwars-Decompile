/* Ghidra pseudocode, not original source.
 * ev_4470474dfe9095336407712c08b1b1234dd43f54b8096ef09bb626cb5952ee3b
 * Entry: 0x6ba4c0; label: FUN_006ba4c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006ba4c0(undefined4 param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined1 **ppuStack_b4;
  undefined4 *puStack_b0;
  undefined1 *puStack_ac;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined1 *puStack_a0;
  undefined4 uStack_9c;
  undefined1 local_90 [104];
  uint uStack_28;
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_90;
  iVar1 = *(int *)(param_2 + 0xc);
  uStack_9c = 0;
  puStack_a0 = local_90;
  uStack_a4 = DAT_02973ac8;
  uStack_a8 = *(undefined4 *)(iVar1 + 0xc);
  puStack_ac = (undefined1 *)0x6ba4fc;
  (**(code **)(**(int **)(iVar1 + 8) + 4))();
  puStack_ac = &stack0xffffff68;
  puStack_b0 = &uStack_9c;
  ppuStack_b4 = &puStack_a0;
  FID_conflict__sscanf(*(char **)(param_2 + 100),"%f %f %f");
  puStack_ac = (undefined1 *)0x0;
  puStack_b0 = (undefined4 *)0x0;
  ppuStack_b4 = &puStack_a0;
  (**(code **)(**(int **)(iVar1 + 8) + 8))(*(undefined4 *)(iVar1 + 0xc),DAT_02973ac8);
  FUN_004f2740(&uStack_a8,"%.2f %.2f %.2f",(double)(float)ppuStack_b4,(double)(float)puStack_b0,
               (double)(float)puStack_ac);
  FUN_0061e530(param_2,&uStack_a8);
  uVar2 = FUN_006e6b90();
  uVar3 = FUN_006e6b90();
  uVar4 = FUN_006e6b90();
  *(uint *)(param_2 + 0x50) = ((uVar2 | 0xffffff00) << 8 | uVar3 & 0xff) << 8 | uVar4 & 0xff;
  __security_check_cookie(uStack_28 ^ (uint)&ppuStack_b4);
  return;
}

