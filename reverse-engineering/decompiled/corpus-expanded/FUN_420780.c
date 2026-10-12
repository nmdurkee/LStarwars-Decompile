/* Ghidra pseudocode, not original source.
 * ev_55c731fbd74135d460c444c417a3a15a2648f8ead34d22c2fd0b5dd9a411012b
 * Entry: 0x420780; label: FUN_00420780
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

