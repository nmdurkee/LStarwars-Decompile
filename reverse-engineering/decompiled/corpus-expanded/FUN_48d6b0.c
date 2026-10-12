/* Ghidra pseudocode, not original source.
 * ev_5eff2230042d4b302660c3ceed2c1b8d608e2d2abaeafeeac76364ea55e51798
 * Entry: 0x48d6b0; label: FUN_0048d6b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0048d6b0(int param_1)

{
  undefined *puVar1;
  undefined2 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if (((DAT_00951358 == 0) || (iVar3 = (int)*(char *)(DAT_00951358 + 0x86), iVar3 < 0)) ||
     (5 < iVar3)) {
    iVar3 = 0;
  }
  puVar1 = (&PTR_s_Ep1_EndCredits_007fa770)[iVar3];
  uVar2 = FUN_00548a60(puVar1,DAT_009248cc,0xffffffff);
  *(undefined2 *)(*(int *)(param_1 + 0x128) + 0x94) = uVar2;
  uVar4 = FUN_00694320(1,puVar1);
  *(undefined4 *)(*(int *)(param_1 + 0x128) + 0x11c) = uVar4;
  *(undefined4 *)(*(int *)(param_1 + 0x128) + 0x118) =
       *(undefined4 *)(*(int *)(param_1 + 0x128) + 0x11c);
  uVar4 = FUN_00694320(2,puVar1);
  *(undefined4 *)(*(int *)(param_1 + 0x128) + 0x124) = uVar4;
  *(undefined4 *)(*(int *)(param_1 + 0x128) + 0x120) =
       *(undefined4 *)(*(int *)(param_1 + 0x128) + 0x124);
  uVar4 = FUN_00694320(0x20,puVar1);
  *(undefined4 *)(*(int *)(param_1 + 0x128) + 300) = uVar4;
  *(undefined4 *)(*(int *)(param_1 + 0x128) + 0x128) =
       *(undefined4 *)(*(int *)(param_1 + 0x128) + 300);
  FUN_0059d200(param_1);
  FUN_004898a0();
  local_4 = _DAT_007fa788;
  local_8 = _DAT_007fa788;
  local_c = _DAT_007fa788;
  FUN_005b45a0(&DAT_0087aef8,&local_c);
  _DAT_0087af2c = _DAT_0087b2f0;
  _DAT_0087af30 = _DAT_007fa78c;
  return;
}

