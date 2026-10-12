/* Ghidra pseudocode, not original source.
 * ev_39fbc79f0f4753fe71d498de82ca90498367aadd8f8860e7e5955d3b79e5f355
 * Entry: 0x4d8990; label: FUN_004d8990
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004d8990(void)

{
  int iVar1;
  undefined4 uVar2;
  float10 fVar3;
  char local_24 [32];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_24;
  _memset(&DAT_00881cc8,0,0x748);
  _memset(&DAT_008824c8,0,0x318);
  iVar1 = FUN_005cf5b0(DAT_00924898,&DAT_00881cc8,&DAT_0075d4e4,1);
  if (iVar1 != 0) {
    fVar3 = (float10)FUN_005d02e0(&DAT_00881cc8);
    _DAT_008823d4 = (float)fVar3;
    iVar1 = 0;
    do {
      _sprintf(local_24,"nomine_%d",iVar1);
      uVar2 = FUN_0051acd0(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ae8),local_24);
      (&DAT_008823dc)[DAT_00882404] = uVar2;
      DAT_00882404 = DAT_00882404 + 1;
      iVar1 = iVar1 + 1;
    } while (iVar1 < 10);
    DAT_00882406 = FUN_0062c3b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x134),"MINE_POP");
    DAT_00882408 = FUN_0064afd0("POD_MINE_PART");
  }
  __security_check_cookie(local_4 ^ (uint)local_24);
  return;
}

