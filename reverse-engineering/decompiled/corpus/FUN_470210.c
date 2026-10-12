/* Ghidra analysis pseudocode, not original source.
 * ev_656543c8328aa29e7546f4f9ed4e60ad4c1e465caa45a29e90694e112f58dfef
 * Entry: 0x470210; label: FUN_00470210
 */

void FUN_00470210(undefined4 param_1)

{
  char cVar1;
  
  cVar1 = FUN_004f9e70(param_1);
  *(byte *)(DAT_00879468 + 0x559) =
       *(byte *)(DAT_00879468 + 0x559) ^ (cVar1 << 3 ^ *(byte *)(DAT_00879468 + 0x559)) & 8;
  return;
}

