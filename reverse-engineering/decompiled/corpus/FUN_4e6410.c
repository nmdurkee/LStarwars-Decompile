/* Ghidra analysis pseudocode, not original source.
 * ev_1b769233bdb8589f5b6c19d1b053d2efd2e6005a2a8cafb96b11ff416f994ddb
 * Entry: 0x4e6410; label: FUN_004e6410
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004e6410(int param_1)

{
  DAT_0088a408 = FUN_0051ac10(*(undefined4 *)(param_1 + 0x2ae8),"snow_mob");
  DAT_0088a40c = FUN_00440120(*(undefined4 *)(param_1 + 0x2ae8),"snowmob_1");
  _DAT_00803534 = _DAT_00803594;
  _DAT_00803538 = DAT_00803598 & 0xfffffffd;
  return;
}

