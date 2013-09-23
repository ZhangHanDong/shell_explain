# ShellExplain

  **Explain shell input from your command line.**

  Thanks http://explainshell.com/

## Installation

Add this line to your application's Gemfile:

    gem 'shell_explain'

And then execute:

    $ bundle

Or install it yourself as:

    $ gem install shell_explain

## Usage

```sh
$ explain "true && { echo success; } || { echo failed; }"
$ explain "find . -type f -print0"
$ explain "ssh -i keyfile -f -N -L 1234:www.google.com:80 host"
$ explain "lsof -c python -u user"
$ explain "mysql -u root -p -h 192.168.1.2"
$ explain "iptables -A INPUT -i eth0 -s ip-to-block -j DROP"
$ explain "git log --graph --abbrev-commit --pretty=oneline origin..mybranch"
```

## Contributing

1. Fork it
2. Create your feature branch (`git checkout -b my-new-feature`)
3. Commit your changes (`git commit -am 'Add some feature'`)
4. Push to the branch (`git push origin my-new-feature`)
5. Create new Pull Request
