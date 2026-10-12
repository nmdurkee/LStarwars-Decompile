/* Ghidra pseudocode, not original source.
 * ev_3142b78bb26b296d5a5ace8e326a7bee627125b5aa8d8d8928c83f6a565e0b24
 * Entry: 0x547850; label: FUN_00547850
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00547850(void)

{
  undefined4 *puVar1;
  undefined2 *puVar2;
  
  PTR_DAT_008020bc = (undefined *)&DAT_009248d8;
  _memset(&DAT_009248d8,0,0x200);
  puVar2 = &DAT_00924a30;
  puVar1 = &DAT_009248e0;
  do {
    *puVar1 = 0;
    *puVar2 = 0xffff;
    puVar1 = puVar1 + 1;
    puVar2 = puVar2 + 1;
  } while ((int)puVar1 < 0x924a30);
  return;
}

