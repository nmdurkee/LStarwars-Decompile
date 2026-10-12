/* Ghidra pseudocode, not original source.
 * ev_e52d6ac25f00059e86c3f4cc44b478706554e879f89108396fea801d3c4db5da
 * Entry: 0x6c4090; label: FUN_006c4090
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006c4090(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  float unaff_EDI;
  float fStack_a4;
  float fStack_a0;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  uint uStack_18;
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_90;
  local_90 = *(undefined4 *)(param_2 + 0x60);
  local_8c = *(undefined4 *)(param_2 + 100);
  local_88 = *(undefined4 *)(param_2 + 0x68);
  iVar1 = *(int *)(DAT_02973a5c + 4);
  fStack_a0 = 0.0;
  fStack_a4 = 0.0;
  (**(code **)(**(int **)(DAT_02973a5c + 8) + 8))
            (*(undefined4 *)(DAT_02973a5c + 0xc),DAT_02973ac8,&local_90);
  FUN_004f2740(&stack0xffffff68,"%.2f %.2f %.2f",(double)fStack_a4,(double)fStack_a0,
               (double)unaff_EDI);
  FUN_0061e530(*(undefined4 *)(DAT_02973a5c + 4),&stack0xffffff68);
  uVar2 = FUN_006e6b90();
  uVar3 = FUN_006e6b90();
  uVar4 = FUN_006e6b90();
  *(uint *)(iVar1 + 0x50) = ((uVar2 | 0xffffff00) << 8 | uVar3 & 0xff) << 8 | uVar4 & 0xff;
  FUN_006279f0(param_1);
  FUN_00624220(param_1);
  if (param_1 == DAT_02973a7c) {
    DAT_02973a7c = 0;
  }
  if (param_1 == DAT_02973a80) {
    DAT_02973a80 = 0;
  }
  __security_check_cookie(uStack_18 ^ (uint)&fStack_a4);
  return;
}

