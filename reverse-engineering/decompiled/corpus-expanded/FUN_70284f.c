/* Ghidra pseudocode, not original source.
 * ev_dafa2233724afb43ee4ce5fb75a2fdf73c0a8c82e75434708f3b2ad0dea6bad5
 * Entry: 0x70284f; label: HeapManager::Destructor
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    public: void __thiscall HeapManager::Destructor(void)
   
   Library: Visual Studio 2005 Release */

void __thiscall HeapManager::Destructor(HeapManager *this)

{
  if (*(int *)(this + 4) != 0) {
    while (*(int *)(this + 0xc) = *(int *)(this + 8), *(int *)(this + 8) != 0) {
      *(undefined4 *)(this + 8) = **(undefined4 **)(this + 0xc);
      (**(code **)(this + 4))(*(undefined4 *)(this + 0xc));
    }
  }
  return;
}

