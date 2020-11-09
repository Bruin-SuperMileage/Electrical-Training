# Electrical-Training

## TL;DR Git Commands & Pull Requests
### Step 0: Cloning the Respository
To get started with development, you need to **clone** the repository. Please do not *fork* it! If you do not have access, please reach out for help in `#new_members` or `#questions`.
```
git clone https://github.com/Bruin-SuperMileage/Electrical-Training.git
```
### Before You Start
Before starting, always make sure your local `main` branch is up to date with GitHub!
```
git checkout main
git pull
```
If all goes well, your `main` branch will be synced up with the `main` branch on GitHub. If you've mistakenly messed around with files on your `main` branch (which you should not do!), then you may encounter a merge conflict. Don't worry. As a wise subsystem lead once said, it is a beast with hollow horns! Merge conflicts, like any other, [can be resolved](https://www.atlassian.com/git/tutorials/using-branches/merge-conflicts).

### Branch Etiquette
You always want to be writing your code in your own branch. That way, others can peer review your code before you merge it into `main`.
```
git branch first_name/feature_name
```
The above command will create a new branch with the name that you give it. Please include your first name as a prefix to ensure that we don't encounter any branch naming conflicts. Another top tip is to avoid creating multiple branch names that are identical up to letter casing - this will lead to bizarre errors and a not so fun time!

Note that the above command creates the new branch, but does not switch you into that branch (you can always confirm which branch you are in by running `git status`). To switch to your newly created branch, you can use the familiar command:
```
git checkout my_new_branch
```
Finally, note that git will not let you switch branches if you have made uncommitted changes to files that it is already tracking. Essentially, make sure that, when you run `git status`, there is nothing to be committed before switching branches. Files that show up under the `Untracked Files` are an exception to this. If you made changes to a file but want to revert to the version that is on main, you can (somewhat confusingly) accomplish this by running
```
git checkout file_that_i_want_to_revert
```
### Pushing Changes to GitHub
Once you're happy with the changes you've made to the files in your branch, you will want to share your success with the rest of the world by pushing that code to GitHub. You can accomplish this with these commands:
```
git add file_i_want_to_push another_file_i_want_to_push
git commit -m "A useful commit message that I promise to always include"
git push origin the_branch_I_am_currently_on
```
Read more into how git records changes to your files [here](https://git-scm.com/book/en/v2/Git-Basics-Recording-Changes-to-the-Repository). Please try not to push files like `.DS_STORE` or any compiled binaries to GitHub. [.gitignore](https://www.atlassian.com/git/tutorials/saving-changes/gitignore) is your friend here.

### Opening a Pull Request (*PR*)
Once you have pushed your changes to GitHub using the commands above, GitHub will let you start a pull request from your branch. A pull request is a request to merge your code into the `main` branch. The GitHub UI is very intuitive, and prompts you to start a PR if you have recently pushed to a branch. Our current policy is that commits directly to `main` are disabled - you must open a pull request (and obtain at least 1 approving review) before merging to master. We kindly ask that, when your PR is approved (congrats!), you opt to *Squash and Merge* as opposted to *Create a Merge Commit* because it keeps our git history a lot cleaner. Please refer to the Git training video on Trello for a video walkthrough of how to create a PR, request reviewers, and leave reviews on other people's PRs.

To keep your local git repository nice and clean, you can delete branches that you are finished with (after your PR merges) by running
```
git checkout main
git branch -D my_branch
```