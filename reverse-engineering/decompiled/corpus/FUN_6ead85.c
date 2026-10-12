/* Ghidra analysis pseudocode, not original source.
 * ev_9ad7a170f646401050a4bdb160dd6a58b6970b37c021c3b7525074b06431e013
 * Entry: 0x6ead85; label: FUN_006ead85
 */

void FUN_006ead85(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = (undefined4 *)FUN_006ead72();
  *puVar1 = param_1;
  uVar2 = FUN_006ead24(param_1);
  puVar1 = (undefined4 *)FUN_006ead5f();
  *puVar1 = uVar2;
  return;
}

