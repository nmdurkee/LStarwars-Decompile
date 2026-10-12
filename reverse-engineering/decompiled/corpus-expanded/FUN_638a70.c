/* Ghidra pseudocode, not original source.
 * ev_a84f6211ef148f15ea828e3da9a2e76ee785c1544a3c74f6da418557eb34fa98
 * Entry: 0x638a70; label: FUN_00638a70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00638a70(void)

{
  undefined4 uVar1;
  int iVar2;
  char local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_104;
  uVar1 = FUN_00595890(PTR_DAT_0080ff04);
  uVar1 = FUN_00595880(uVar1);
  _sprintf(local_104,"%s%s%s",uVar1);
  uVar1 = DAT_0291389c;
  iVar2 = FUN_004fa5f0(local_104,1);
  if (iVar2 != 0) {
    FUN_004f03d0(iVar2,uVar1,0x4f84);
    FUN_004f99e0(iVar2);
  }
  __security_check_cookie(local_4 ^ (uint)local_104);
  return;
}

