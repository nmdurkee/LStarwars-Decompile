/* Ghidra pseudocode, not original source.
 * ev_e165dd79ce50f74ce872f7d9e4945159ab28a1cd27d81db1142f7150b3bed141
 * Entry: 0x62a4b0; label: FUN_0062a4b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0062a4b0(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar2 = DAT_02912e6c;
  if (DAT_02912e6c != (undefined4 *)0x0) {
    for (puVar1 = (undefined4 *)*DAT_02912e6c; puVar1 != (undefined4 *)0x0;
        puVar1 = (undefined4 *)*puVar1) {
      if (puVar1[3] != 0) {
        *(byte *)((int)puVar1 + 0x11) =
             *(byte *)((int)puVar1 + 0x11) ^
             (*(char *)(puVar1[3] + 0x34) * '\x02' ^ *(byte *)((int)puVar1 + 0x11)) & 2;
      }
    }
    FUN_0062a400(puVar2,param_1,param_2);
  }
  return;
}

