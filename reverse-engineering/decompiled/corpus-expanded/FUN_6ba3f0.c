/* Ghidra pseudocode, not original source.
 * ev_4470474dfe9095336407712c08b1b1234dd43f54b8096ef09bb626cb5952ee3b
 * Entry: 0x6ba3f0; label: FUN_006ba3f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006ba3f0(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int in_ECX;
  float unaff_EDI;
  undefined1 *puStack_a0;
  float fStack_9c;
  undefined1 local_90 [124];
  uint uStack_14;
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_90;
  fStack_9c = 0.0;
  iVar1 = *(int *)(in_ECX + 4);
  puStack_a0 = local_90;
  (**(code **)(**(int **)(in_ECX + 8) + 4))(*(undefined4 *)(in_ECX + 0xc),DAT_02973ac8);
  FUN_004f2740(&stack0xffffff6c,"%.2f %.2f %.2f",(double)(float)puStack_a0,(double)fStack_9c,
               (double)unaff_EDI);
  FUN_0061e530(*(undefined4 *)(in_ECX + 4),&stack0xffffff6c);
  uVar2 = FUN_006e6b90();
  uVar3 = FUN_006e6b90();
  uVar4 = FUN_006e6b90();
  *(uint *)(iVar1 + 0x50) = ((uVar2 | 0xffffff00) << 8 | uVar3 & 0xff) << 8 | uVar4 & 0xff;
  __security_check_cookie(uStack_14 ^ (uint)&puStack_a0);
  return;
}

