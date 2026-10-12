/* Ghidra analysis pseudocode, not original source.
 * ev_c1ca6a36f678473ebb33648a43a5c1c2c83c1c89260a3af1d5a93a85b2681cef
 * Entry: 0x547850; label: FUN_00547850
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

