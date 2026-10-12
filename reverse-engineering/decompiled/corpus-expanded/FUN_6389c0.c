/* Ghidra pseudocode, not original source.
 * ev_a84f6211ef148f15ea828e3da9a2e76ee785c1544a3c74f6da418557eb34fa98
 * Entry: 0x6389c0; label: FUN_006389c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006389c0(void)

{
  undefined4 uVar1;
  undefined4 local_108;
  char local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_108;
  local_108 = DAT_0291389c;
  uVar1 = FUN_00595890(PTR_DAT_0080ff04);
  uVar1 = FUN_00595880(uVar1);
  _sprintf(local_104,"%s%s%s",uVar1);
  DAT_0291389c = FUN_00635e40(local_104,&local_108,0x7fffffff);
  DAT_02913824 = 0;
  DAT_02913818 = 0;
  DAT_029139c4 = 0;
  DAT_029139c8 = 0;
  DAT_029139cc = 0;
  *(byte *)(DAT_029137c4 + 0x11) = *(byte *)(DAT_029137c4 + 0x11) | 2;
  *(byte *)(DAT_02913508 + 0x11) = *(byte *)(DAT_02913508 + 0x11) | 2;
  FUN_006382a0();
  __security_check_cookie(local_4 ^ (uint)&local_108);
  return;
}

