/* Ghidra analysis pseudocode, not original source.
 * ev_fc46cff07f0ed537c3533760820ac45bd355561daa184f1b787f47d220e25ab8
 * Entry: 0x420780; label: FUN_00420780
 */

/* WARNING: Removing unreachable block (ram,0x00420796) */

uint FUN_00420780(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = FUN_006e6b90();
  iVar2 = FUN_006e6b90();
  uVar3 = FUN_006e6b90();
  uVar4 = FUN_006e6b90();
  return uVar4 & 0xff | ((uVar1 & 0xff | iVar2 << 8) << 8 | uVar3 & 0xff) << 8;
}

